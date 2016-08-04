public static int task_schedule(int[] input, int interval){
            if(input == null || input.length == 0){
              return 0;
            }
            if(interval < 0){
              return 0;
            }
            Map<Integer, Integer> map = new HashMap<Integer, Integer>();. more info on 1point3acres.com
            int currTime = 0;
            int i = 0;
            for(int task : input){
                    if(map.containsKey(task)){
                            int startTime = map.get(task);
                            if(startTime <= currTime){
                                    currTime++;
                            }else{
                                    currTime = startTime;
                                    currTime++;
                            }
                    }else{
                            currTime++;
                    }
                    map.put(task, currTime + interval);
            }
            return currTime;
          }. 