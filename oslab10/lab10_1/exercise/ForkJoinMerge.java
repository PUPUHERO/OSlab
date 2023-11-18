import java.util.concurrent.ExecutionException;
import java.util.concurrent.ForkJoinPool;
import java.util.concurrent.RecursiveTask;
import java.util.stream.LongStream;
import java.util.Arrays;

public class ForkJoinMerge {

    private ForkJoinPool pool;

    private static class MergeTask extends RecursiveTask<Long>{
        private long[] array;
        private int left, middle, right;

        public MergeTask(long[] array, int left, int right) {
            this.array = array;
            this.left = left;
            this.right = right;
            this.middle = (left + right) / 2;
        }

        protected Long compute(){
            if (left < right){
                MergeTask task1 = new MergeTask(array, left, middle);
                MergeTask task2 = new MergeTask(array, middle+1, right);
                task1.fork();
                task2.fork();
                task1.join(); 
                task2.join();
                merge();
            }
            return 0L;
        }

        private long[] merge(){
            //array copy
            int n1 = middle - left + 1;
            int n2 = right - middle;

            long[] L = new long[n1];
            long[] R = new long[n2];

            for (int i = 0; i < n1; ++i) {
                L[i] = array[left + i];
            }
            for (int j = 0; j < n2; ++j) {
                R[j] = array[middle + 1 + j];
            }
            // now we have two arrays
            //==================================================================
            // merge two arrays
            int i = 0, j = 0;
            int k = left;
            while (i < n1 && j < n2) {
                if (L[i] <= R[j]) {
                    array[k] = L[i];
                    i++;
                } else {
                    array[k] = R[j];
                    j++;
                }
                k++;
            }

            while (i < n1) {
                array[k] = L[i];
                i++;
                k++;
            }

            while (j < n2) {
                array[k] = R[j];
                j++;
                k++;
            }
            return array;
        }
    }
    public ForkJoinMerge(){
        pool = new ForkJoinPool();
    }

    public long Merge_Fork(long[] array){
        return pool.invoke(new MergeTask(array, 0, array.length-1));
    }
}