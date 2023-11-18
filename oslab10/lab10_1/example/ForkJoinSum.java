import java.util.concurrent.ExecutionException;
import java.util.concurrent.ForkJoinPool;
import java.util.concurrent.RecursiveTask;
import java.util.stream.LongStream;
import java.util.Arrays;

public class ForkJoinSum implements sumOfArray {

    private ForkJoinPool pool;

    private static class SumTask extends RecursiveTask<Long>{
        private long[] numbers;
        private int from;
        private int to;

        public SumTask(long[] numbers, int from, int to) {
            this.numbers = numbers;
            this.from = from;
            this.to = to;
        }

        protected Long compute(){
            if (to-from < 6){
                long total = 0;
                for (int i = from; i <= to; i++){
                    total += numbers[i];
                }
                return total;
            }
            else{
                int split = (from + to) / 2;
                SumTask task1 = new SumTask(numbers, from, split);
                SumTask task2 = new SumTask(numbers, split+1, to);
                task1.fork();
                return task2.compute() + task1.join();
            }
        }
    }
    public ForkJoinSum(){
        pool = new ForkJoinPool();
    }

    public long sumUP(long[] numbers){
        return pool.invoke(new SumTask(numbers, 0, numbers.length-1));
    }
}