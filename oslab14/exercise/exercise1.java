class Sync{
    private int count = 0;
    public synchronized void increment(){
        count++;
    }
    public synchronized void decrement(){
        count--;
    }
    public synchronized int getCount(){
        return count;
    }
}

public class exercise1 {
    public static void main(String[] args) throws InterruptedException {
        Sync sync = new Sync();
        Thread t1 = new Thread(new Runnable(){
            public void run(){
                for(int i=0; i<25000000;i++){
                    sync.increment();
                }
            }
        });
        Thread t2 = new Thread(new Runnable(){
            public void run(){
                for(int i=0; i<25000000;i++){
                    sync.decrement();
                }
            }
        });
        Thread t3 = new Thread(new Runnable(){
            public void run(){
                for(int i=0; i<25000000;i++){
                    sync.increment();
                }
            }
        });
        Thread t4 = new Thread(new Runnable(){
            public void run(){
                for(int i=0; i<25000000;i++){
                    sync.decrement();
                }
            }
        });
        t1.start();
        t2.start();
        t3.start();
        t4.start();
        t1.join();
        t2.join();
        t3.join(); 
        t4.join();
        System.out.println("Count:" + sync.getCount());
    }
}
