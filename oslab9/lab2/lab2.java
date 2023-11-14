
public class lab2 {
    static int count = 0;
    public static void main(String argv[]) {
        // IntegerWrapper count = new IntegerWrapper(0);
        int threadCount = 4;
        
        Thread Tarray[] = new Thread[threadCount];

        for (int i = 0; i < threadCount; i++) {
            Tarray[i] = new Thread(new adding());
            Tarray[i].start();
        }


        for(int i=0;i<threadCount;i++){
            try{
                Tarray[i].join();
            }catch(InterruptedException e){
                e.printStackTrace();
            }
        }
        System.out.println("Final count value:"+count);
    }
    
    static class adding implements Runnable {
        public void run(){
            for(int i=0;i<250000;i++){
                count+=1;
            }
            System.out.println("Thread name is "+Thread.currentThread().getName()+" and count is "+ count);
        }
    }
}
