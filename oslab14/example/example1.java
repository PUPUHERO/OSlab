import java.lang.Thread;

class job implements Runnable {
    public synchronized void run(){
        for(int i=0; i<25000000;i++){
            example1.c++;
        }
    }
}

public class example1 {
    public static int c = 0;
    public static void main(String[] args) throws InterruptedException {
        job j = new job();
        Thread t1 = new Thread(j);
        Thread t2 = new Thread(j);
        Thread t3 = new Thread(j);
        t1.start();
        t2.start();
        t3.start();
        t1.join();
        t2.join();
        t3.join(); 
        System.out.println(c);
    }
}