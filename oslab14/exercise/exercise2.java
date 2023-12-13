import java.util.concurrent.locks.*;

class Warehouse
{
    private Lock lock = new ReentrantLock();
    private Condition threadCond = lock.newCondition();

    private int product = 0;

    public void setProduct()
    {
        lock.lock();
        try
        {
            while (product >= 10)
            {
                try
                {
                    System.out.printf("FULL\n");
                    threadCond.await();
                }
                catch (InterruptedException e)
                {
                    e.printStackTrace();
                }
            }
            product++;
            System.out.println("made a product:" + product);
            threadCond.signalAll();
        }
        finally
        {
            lock.unlock();
        }
    }
    public void getProduct()
    {
        lock.lock();
        try
        {
            while (product <= 0)
            {
                try
                {
                    System.out.printf("EMPTY\n");
                    threadCond.await();
                }
                catch (InterruptedException e)
                {
                    e.printStackTrace();
                }
            }
            product--;
            System.out.println("got a product:" + product);
            threadCond.signalAll();
        }
        finally
        {
            lock.unlock();
        }
    }
}

public class exercise2 {
    public static void main(String[] args) throws InterruptedException {
        Warehouse warehouse = new Warehouse();
        Thread t1 = new Thread(new Runnable(){
            public void run(){
                for(int i=0; i<100;i++){
                    warehouse.setProduct();
                }
            }
        });
        Thread t2 = new Thread(new Runnable(){
            public void run(){
                for(int i=0; i<100;i++){
                    warehouse.getProduct();
                }
            }
        });
        Thread t3 = new Thread(new Runnable(){
            public void run(){
                for(int i=0; i<100;i++){
                    warehouse.setProduct();
                }
            }
        });
        Thread t4 = new Thread(new Runnable(){
            public void run(){
                for(int i=0; i<100;i++){
                    warehouse.getProduct();
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
    }
}
