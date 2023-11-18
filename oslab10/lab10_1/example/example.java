import java.util.*;
import java.util.concurrent.*;
import java.util.stream.LongStream;

public class example {
    public static void main(String[] args){
        long[] numbers = LongStream.rangeClosed(1, 100).toArray();
        
        sumOfArray sum = new ForkJoinSum();

        System.out.println(sum.sumUP(numbers));
    }
}
