var VSHADER_SOURCE =
  //-------------Set precision.
  // GLSL-ES 2.0 defaults (from spec; '4.5.3 Default Precision Qualifiers'):
  // DEFAULT for Vertex Shaders:  precision highp float; precision highp int;
  //                  precision lowp sampler2D; precision lowp samplerCube;
  // DEFAULT for Fragment Shaders:  UNDEFINED for float; precision mediump int;
  //                  precision lowp sampler2D; precision lowp samplerCube;
  //--------------- GLSL Struct Definitions:
  'struct MatlT {\n' +    // Describes one Phong material by its reflectances:
  '   vec3 emit;\n' +     // Ke: emissive -- surface 'glow' amount (r,g,b);
  '   vec3 ambi;\n' +     // Ka: ambient reflectance (r,g,b)
  '   vec3 diff;\n' +     // Kd: diffuse reflectance (r,g,b)
  '   vec3 spec;\n' +     // Ks: specular reflectance (r,g,b)
  '   int shiny;\n' +     // Kshiny: specular exponent (integer >= 1; typ. <200)
  '   };\n' +

  'struct LampT {\n' +    // Describes one point-like Phong light source
  '   vec3 pos;\n' +      // (x,y,z,w); w==1.0 for local light at x,y,z position
                          //       w==0.0 for distant light from x,y,z direction 
  '   vec3 ambi;\n' +     // Ia ==  ambient light source strength (r,g,b)
  '   vec3 diff;\n' +     // Id ==  diffuse light source strength (r,g,b)
  '   vec3 spec;\n' +     // Is == specular light source strength (r,g,b)
  '}; \n' +
  //                                
  //-------------ATTRIBUTES of each vertex, read from our Vertex Buffer Object
  'attribute vec4 a_Position; \n' +   // vertex position (model coord sys)
  'attribute vec4 a_Normal; \n' +     // vertex normal vector (model coord sys)
  'attribute vec4 a_Color;\n' +

                    
  //-------------UNIFORMS: values set from JavaScript before a drawing command.
//  'uniform vec3 u_Kd; \n' +           // Phong diffuse reflectance for the 
                                      // entire shape. Later: as vertex attrib.
  //'uniform MatlT u_MatlSet[1];\n' +   // Array of all materials.
  'uniform mat4 u_MvpMatrix; \n' +
  'uniform mat4 u_ModelMatrix; \n' +    // Model matrix
  'uniform mat4 u_NormalMatrix; \n' +   // Inverse Transpose of ModelMatrix;
                                        // (won't distort normal vec directions
                                        // but it usually WILL change its length)
  
  //-------------VARYING:Vertex Shader values sent per-pixel to Fragment shader:
  'varying vec3 v_Kd; \n' +             // Phong Lighting: diffuse reflectance
                                        // (I didn't make per-pixel Ke,Ka,Ks;
                                        // we use 'uniform' values instead)
  'varying vec4 v_Position; \n' +       
  'varying vec3 v_Normal; \n' +         // Why Vec3? its not a point, hence w==0


  'uniform LampT u_LampSet[2];\n' +   // Array of all light sources.
  'uniform MatlT u_MatlSet[1];\n' +   // Array of all materials.
  
  //==========for garaud ==============
  'uniform vec3 u_eyePosWorld; \n' +  // Camera/eye location in world coords.

  'uniform int v_PHONG;\n' + 
  'uniform int v_MAINLIGHT;\n' +
  'uniform int v_HEADLIGHT;\n' +
  'uniform int v_GOURAUD;\n' +

  'varying vec4 g_color;\n' + 

  'void main() { \n' +
    // Compute CVV coordinate values from our given vertex. This 'built-in'
    // 'varying' value gets interpolated to set screen position for each pixel.
  '  gl_Position = u_MvpMatrix * a_Position;\n' +
    // Calculate the vertex position & normal vec in the WORLD coordinate system
    // for use as a 'varying' variable: fragment shaders get per-pixel values
    // (interpolated between vertices for our drawing primitive (TRIANGLE)).
  '  v_Position = u_ModelMatrix * a_Position; \n' +
    // 3D surface normal of our vertex, in world coords.  ('varying'--its value
    // gets interpolated (in world coords) for each pixel's fragment shader.
  '  v_Normal = normalize(vec3(u_NormalMatrix * a_Normal));\n' +
  '  v_Kd = u_MatlSet[0].diff; \n' +    // find per-pixel diffuse reflectance from per-vertex

  '  vec3 normal = v_Normal; \n' +
 
  // Find the unit-length light dir vector 'L' (surface pt --> light):
  '  vec3 lightDirection = normalize(u_LampSet[0].pos - v_Position.xyz);\n' +
  '  vec3 lightDirection1 = normalize(u_LampSet[1].pos - v_Position.xyz);\n' +
      // Find the unit-length eye-direction vector 'V' (surface pt --> camera)
  //'  vec3 eyeDirection_w = normalize(g_eyePosWorld_w - v_Position.xyz); \n' +
  '  vec3 eyeDirection = normalize(u_eyePosWorld - v_Position.xyz);\n' + 

      // The dot product of (unit-length) light direction and the normal vector
      // (use max() to discard any negatives from lights below the surface) 
      // (look in GLSL manual: what other functions would help?)
      // gives us the cosine-falloff factor needed for the diffuse lighting term:
  '  float nDotL  = max(dot(lightDirection, normal), 0.0); \n' +
  '  float nDotL1 = max(dot(lightDirection1, normal), 0.0); \n' +
      // The Blinn-Phong lighting model computes the specular term faster 
      // because it replaces the (V*R)^shiny weighting with (H*N)^shiny,
      // where 'halfway' vector H has a direction half-way between L and V
      // H = norm(norm(V) + norm(L)).  Note L & V already normalized above.
      //(see http://en.wikipedia.org/wiki/Blinn-Phong_shading_model)
  '  vec3 H  = normalize(lightDirection + eyeDirection); \n' +
  '  vec3 H1 = normalize(lightDirection1 + eyeDirection); \n' +

  '  float nDotH  = max(dot(H, normal), 0.0); \n' +
  '  float nDotH1 = max(dot(H1, normal), 0.0); \n' +

  '  float e64  = pow(nDotH, float(u_MatlSet[0].shiny));\n' +
  '  float e641 = pow(nDotH1, float(u_MatlSet[0].shiny));\n' +

  '  if(v_PHONG == 2) { \n' +
  '  vec3 reflectDir = reflect(-lightDirection, normal);' +
  '  vec3 reflectDir1 = reflect(-lightDirection1, normal);' +

  '  nDotH = max(dot(reflectDir, eyeDirection), 0.0);' +
  '  nDotH1 = max(dot(reflectDir1, eyeDirection), 0.0);' +

  '  e64 = pow(nDotH, float(u_MatlSet[0].shiny)/2.0);' +
  '  e641 = pow(nDotH1, float(u_MatlSet[0].shiny)/2.0);' +

  '  }' +


  // Calculate the final color from diffuse reflection and ambient reflection
//  '  vec3 emissive = u_Ke;' +
  '  vec3 emissive =                    u_MatlSet[0].emit;' +
  '  vec3 ambient = u_LampSet[0].ambi * u_MatlSet[0].ambi;\n' +
  '  vec3 diffuse = u_LampSet[0].diff * v_Kd * nDotL;\n' +
  '  vec3 speculr = u_LampSet[0].spec * u_MatlSet[0].spec * e64;\n' +


  '  vec3 emissive1 =                    u_MatlSet[0].emit;' +
  '  vec3 ambient1 = u_LampSet[1].ambi * u_MatlSet[0].ambi;\n' +
  '  vec3 diffuse1 = u_LampSet[1].diff * v_Kd * nDotL1;\n' +
  '  vec3 speculr1 = u_LampSet[1].spec * u_MatlSet[0].spec * e641;\n' +

  ' if(v_MAINLIGHT == 1 && v_HEADLIGHT == 1) {\n' +
  ' g_color = vec4(emissive + emissive1 + ambient + ambient1 + diffuse + diffuse1 + speculr + speculr1, 1.0);\n' +
  ' }\n' +

  ' if(v_MAINLIGHT == 0 && v_HEADLIGHT == 1) {\n' +
  ' g_color = vec4(emissive1 + ambient1 + diffuse1 + speculr1, 1.0);\n' +
  ' }\n' +

  ' if(v_MAINLIGHT == 1 && v_HEADLIGHT == 0) {\n' +
  ' g_color = vec4(emissive + ambient + diffuse + speculr, 1.0);\n' +
  ' }\n' +

  ' if(v_MAINLIGHT == 0 && v_HEADLIGHT == 0) {\n' +
  ' g_color = vec4(0.0, 0.0, 0.0, 1.0);\n' +
  ' }\n' +

'}\n';

//=============================================================================
// Fragment shader program
//=============================================================================
var FSHADER_SOURCE =
  //-------------Set precision.
  // GLSL-ES 2.0 defaults (from spec; '4.5.3 Default Precision Qualifiers'):
  // DEFAULT for Vertex Shaders:  precision highp float; precision highp int;
  //                  precision lowp sampler2D; precision lowp samplerCube;
  // DEFAULT for Fragment Shaders:  UNDEFINED for float; precision mediump int;
  //                  precision lowp sampler2D; precision lowp samplerCube;
  // MATCH the Vertex shader precision for float and int:
  'precision highp float;\n' +
  'precision highp int;\n' +
  //
  //--------------- GLSL Struct Definitions:
  'struct LampT {\n' +    // Describes one point-like Phong light source
  '   vec3 pos;\n' +      // (x,y,z,w); w==1.0 for local light at x,y,z position
                          //       w==0.0 for distant light from x,y,z direction 
  '   vec3 ambi;\n' +     // Ia ==  ambient light source strength (r,g,b)
  '   vec3 diff;\n' +     // Id ==  diffuse light source strength (r,g,b)
  '   vec3 spec;\n' +     // Is == specular light source strength (r,g,b)
  '}; \n' +
  //

  'struct MatlT {\n' +    // Describes one Phong material by its reflectances:
  '   vec3 emit;\n' +     // Ke: emissive -- surface 'glow' amount (r,g,b);
  '   vec3 ambi;\n' +     // Ka: ambient reflectance (r,g,b)
  '   vec3 diff;\n' +     // Kd: diffuse reflectance (r,g,b)
  '   vec3 spec;\n' +     // Ks: specular reflectance (r,g,b)
  '   int shiny;\n' +     // Kshiny: specular exponent (integer >= 1; typ. <200)
  '   };\n' +
  //
  //-------------UNIFORMS: values set from JavaScript before a drawing command.
  // first light source: (YOU write a second one...)
  // 'uniform LampT u_LampSet[2];\n' +   // Array of all light sources.
  'uniform MatlT u_MatlSet[1];\n' +   // Array of all materials.

  'uniform LampT u_LampSet[2];\n' +   // Array of all light sources.
  'uniform vec3 u_eyePosWorld; \n' +
  //-------------VARYING:Vertex Shader values sent per-pix'''''''''''''''';el to Fragment shader: 
  'varying vec3 v_Normal;\n' +        // Find 3D surface normal at each pix
  'varying vec4 v_Position;\n' +      // pixel's 3D pos too -- in 'world' coords
  'varying vec3 v_Kd; \n' +           // Find diffuse reflectance K_d per pix
                            // Ambient? Emissive? Specular? almost
                            // NEVER change per-vertex: I use 'uniform' values
  //Add Uniform attribute is Phone?
  //'uniform float PHONG;\n' +
  'uniform int v_PHONG;\n' + 
  'uniform int v_MAINLIGHT;\n' +
  'uniform int v_HEADLIGHT;\n' +
  'uniform int v_GOURAUD;\n' +

  'varying vec4 g_color;\n' + 

  'void main() { \n' +
      // Normalize! !!IMPORTANT!! TROUBLE if you don't! 
      // normals interpolated for each pixel aren't 1.0 in length any more!
  'vec3 normal = normalize(v_Normal); \n' +

  // Find the unit-length light dir vector 'L' (surface pt --> light):
  '  vec3 lightDirection = normalize(u_LampSet[0].pos - v_Position.xyz);\n' +
  '  vec3 lightDirection1 = normalize(u_LampSet[1].pos - v_Position.xyz);\n' +

      // Find the unit-length eye-direction vector 'V' (surface pt --> camera)
  //'  vec3 eyeDirection_w = normalize(u_eyePosWorld_w - v_Position.xyz); \n' +
  '  vec3 eyeDirection = normalize(u_eyePosWorld - v_Position.xyz);\n' + 

      // The dot product of (unit-length) light direction and the normal vector
      // (use max() to discard any negatives from lights below the surface) 
      // (look in GLSL manual: what other functions would help?)
      // gives us the cosine-falloff factor needed for the diffuse lighting term:
  '  float nDotL  = max(dot(lightDirection, normal), 0.0); \n' +
  '  float nDotL1 = max(dot(lightDirection1, normal), 0.0); \n' +
      // The Blinn-Phong lighting model computes the specular term faster 
      // because it replaces the (V*R)^shiny weighting with (H*N)^shiny,
      // where 'halfway' vector H has a direction half-way between L and V
      // H = norm(norm(V) + norm(L)).  Note L & V already normalized above.
      //(see http://en.wikipedia.org/wiki/Blinn-Phong_shading_model)
  '  vec3 H  = normalize(lightDirection + eyeDirection); \n' +
  '  vec3 H1 = normalize(lightDirection1 + eyeDirection); \n' +

  '  float nDotH  = max(dot(H, normal), 0.0); \n' +
  '  float nDotH1 = max(dot(H1, normal), 0.0); \n' +

  '  float e64  = pow(nDotH, float(u_MatlSet[0].shiny)/2.0);\n' +
  '  float e641 = pow(nDotH1, float(u_MatlSet[0].shiny)/2.0);\n' +

  '  if(v_PHONG == 2) { \n' +
  '  vec3 reflectDir = reflect(-lightDirection, normal);' +
  '  vec3 reflectDir1 = reflect(-lightDirection1, normal);' +

  '  nDotH = max(dot(reflectDir, eyeDirection), 0.0);' +
  '  nDotH1 = max(dot(reflectDir1, eyeDirection), 0.0);' +

  '  e64 = pow(nDotH, float(u_MatlSet[0].shiny)/2.0);' +
  '  e641 = pow(nDotH1, float(u_MatlSet[0].shiny)/2.0);' +

  '  }' +

  '  vec3 emissive =                    u_MatlSet[0].emit;' +
  '  vec3 ambient = u_LampSet[0].ambi * u_MatlSet[0].ambi;\n' +
  '  vec3 diffuse = u_LampSet[0].diff * v_Kd * nDotL;\n' +
  '  vec3 speculr = u_LampSet[0].spec * u_MatlSet[0].spec * e64;\n' +

  '  vec3 emissive1 =                    u_MatlSet[0].emit;' +
  '  vec3 ambient1 = u_LampSet[1].ambi * u_MatlSet[0].ambi;\n' +
  '  vec3 diffuse1 = u_LampSet[1].diff * v_Kd * nDotL1;\n' +
  '  vec3 speculr1 = u_LampSet[1].spec * u_MatlSet[0].spec * e641;\n' +

  ' if(v_GOURAUD == 2) {\n' +
  ' gl_FragColor = g_color;\n' + 
  ' }\n' +
  ' else {\n' + 
  ' if(v_MAINLIGHT == 1 && v_HEADLIGHT == 1) {\n' +
  ' gl_FragColor = vec4(emissive + emissive1 + ambient + ambient1 + diffuse + diffuse1 + speculr + speculr1, 1.0);\n' +
  ' }\n' +

  ' if(v_MAINLIGHT == 0 && v_HEADLIGHT == 1) {\n' +
  ' gl_FragColor = vec4(emissive1 + ambient1 + diffuse1 + speculr1, 1.0);\n' +
  ' }\n' +

  ' if(v_MAINLIGHT == 1 && v_HEADLIGHT == 0) {\n' +
  ' gl_FragColor = vec4(emissive + ambient + diffuse + speculr, 1.0);\n' +
  ' }\n' +

  ' if(v_MAINLIGHT == 0 && v_HEADLIGHT == 0) {\n' +
  ' gl_FragColor = vec4(0.0, 0.0, 0.0, 1.0);\n' +
  ' }\n' +

  ' }\n' +

'}\n';