import java.util.Arrays;
import java.util.Scanner;

//Task C3
public class Main {
	public static void main(String[] args) {
		new Main();
	}
	int sticks[];
	int files[];
	int sticks_used[];
	int sticks_amount;
	int cum_file_size[];
	public Main() {
		Scanner sc = new Scanner(System.in);
		int amount_of_tasks = sc.nextInt();
		for(int current_task = 1; current_task <= amount_of_tasks; ++current_task){
			sticks_amount = sc.nextInt();
			sticks = new int[sticks_amount];
			sticks_used = new int[sticks_amount];
			for(int i = 0; i < sticks_amount; ++i){
				sticks[i]=sc.nextInt();
			}
			Arrays.sort(sticks);
			int files_amount = sc.nextInt();
			files = new int[files_amount];
			cum_file_size = new int[files_amount];
			for(int i = 0; i< files_amount; ++i){
				files[i]=sc.nextInt();
			}
			cum_file_size[0]=files[0];
			for(int i = 1; i < files_amount; ++i){
				cum_file_size[i]=cum_file_size[0]+files[i];
			}
			Arrays.sort(files);
			best = Integer.MAX_VALUE;
			fill(files_amount-1, 0);
			System.out.print(current_task+" ");
			if(best == Integer.MAX_VALUE){
				System.out.println("ONMOGELIJK");
			}else{
				System.out.println(best);
			}
		}
		sc.close();
	}
	int best;
	void fill(int last_file, int current_unused_space){
		if(last_file < 0){
			int current = 0;
			for(int i = 0; i < sticks_amount; ++i){
				if(sticks_used[i]>0)
					current += sticks[i];
			}
			best = Math.min(best, current);
			return;
		}

		if(current_unused_space-cum_file_size[last_file]>=best){
			return;
		}
		for(int i = 0; i < sticks_amount; ++i){
			if(sticks[i]<files[last_file])
				continue;
			int unused = current_unused_space;
			if(sticks_used[i]==0)
				unused += sticks[i];
			sticks[i]-=files[last_file];
			++sticks_used[i];
			fill(last_file-1, unused-files[last_file]);
			sticks[i]+=files[last_file];
			--sticks_used[i];
		}
	}
}
