
import java.io.IOException;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

public class reduce_log extends Reducer<Text, IntWritable, Text, IntWritable> {
    public void reduce(Text key, Iterable<IntWritable> values, Context context) throws IOException,
    InterruptedException {
        int sum = 0;
        int max1 = 0 ;
        int newmax= 0 ;
        int i =0;
        for (IntWritable val : values) {
            sum += val.get();
           
            
        }
      
        	context.write(key, new IntWritable(sum));
        
         
    }
    }
