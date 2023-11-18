import java.util.concurrent.ThreadLocalRandom;
import java.util.stream.LongStream;

public class exercise {
    public static void main(String[] args){
        long[] numbers = LongStream.rangeClosed(1, 100).toArray();
        
        // print out original array
        printArray(numbers);

        // shuffle array
        shuffleArray(numbers);

        // print out shuffled array
        printArray(numbers);

        ForkJoinMerge mergeTool = new ForkJoinMerge();

        mergeTool.Merge_Fork(numbers);

        printArray(numbers);
    }

    //print out array
    public static void printArray(long[] array){
        for (int i = 0; i < array.length; i++){
            System.out.print(array[i] + " ");
        }
        System.out.println("\n");
    }

    public static void shuffleArray(long[] array) {
        ThreadLocalRandom random = ThreadLocalRandom.current();
        for (int i = array.length - 1; i > 0; i--) {
            // 生成 0 到 i（含）之間的隨機索引
            int j = random.nextInt(i + 1);

            // 將當前元素和隨機選擇的元素進行交換
            long temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
}
