import java.util.BitSet;
import java.util.Scanner;
import java.util.LinkedList;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.FileReader;


/*
* stats:
* java, L=1000, H=1000, N=500 -> 2.01 sec
*/


public class Code {
	
	public static void main(String[] args) {
		
		for (int x=1 ; x<=20;x++){
		try {
			BufferedReader in = new BufferedReader(new FileReader("input"+x+".txt"));
		 	PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("sol"+x+".txt")));
		
			String[] sizes = in.readLine().split(" ");
			int width = new Integer(sizes[0]);
			int height = new Integer(sizes[1]);
			int N = new Integer(sizes[2]);
			
			Grid g = new Grid(width, height);
	
			for (int i = 0; i< N; i++) {
				sizes = in.readLine().split(" ");
				int w = new Integer(sizes[0]);
				int h = new Integer(sizes[1]);
				
				//	System.out.println(w+" "+h);
				
				Grid.Pair p = g.place(w, h);
				if(p==null){ System.out.println(x+"- null at "+i);System.exit(0);}
				//System.out.println("->"+p.x+" "+p.y);
				//System.out.println(g);
				out.println(p.x+" "+p.y);
				
			}
			
			in.close();
			out.close();
		
		} catch (IOException e) {}
	 }
						
	}
	
	public static class Grid {
		
		LinkedList<Column> cols = new LinkedList<Column>() ;
		int width;
		int height;	
		int firstindex = 0;
		
		public Grid(int w, int h) {
			width=w;
			height=h;
		}		
		
		public String toString(){
			String s = "";
			for (Column c: cols) {
				s += c+"\n";
			}
			return s;
		}
		
		public Pair place(int w, int h){
		
			int i=firstindex;
			
			while(i < width) { // find the startup at another column
				
				Column c = getColum(i);
				int freey = c.nexty(0);
				
			//	System.out.print("."+freey+ ","+h+","+height);
				
				while (freey+h <= height) { // find another startup y
			//		System.out.print("*"+i);
					
					if (freeFromThisCorner(i, freey, w, h)) {
						
						setOccupied(i, freey, w, h);
						clear();
						
						return new Pair(i, freey);
					}
					freey = c.nexty(freey+1);
					
				}
				i++;
				
			}
			return null;
		
		}
		
		public void clear() {
			
			Column c = cols.getFirst() ;
			while( cols.size() > 1 && (c.col).nextClearBit(0) >= height ){  
				cols.remove();
				firstindex++;
				c = cols.getFirst() ;
			}
		//	System.out.println("x");
		}
		
		public Column getColum(int index) {
			try {
				return cols.get(index-firstindex);
			} catch (java.lang.IndexOutOfBoundsException e) {
				Column c = new Column(index);
				cols.add(c);
				return c;				
			}
		}
		
		public boolean freeFromThisCorner(int colx, int y, int w, int h) {
			
			for (int i = colx; i < colx+w; i++) {
				if (! getColum(i).freeConseq( y, h )) return false; 
			}
			//System.out.print("!");
			return true;
		}
		
		public void setOccupied(int colx, int y, int w, int h) {
			
			for (int i = colx; i < colx+w; i++) {
				getColum(i).setOccupied( y, h ) ;
			}
		}

		
		public class Pair {
			int x, y;
			public Pair(int x, int y) {
				this.x=x;
				this.y=y;
			}
		}
		
		public class Column {

			BitSet col = new BitSet(height); // false = empty, by default, full empty
			int x;

			public Column(int x) {
				this.x = x;		
			}
			
			public String toString(){
				return "col:"+x+" - "+ col;
			}
			
			public int nexty(int y){
				return col.nextClearBit(y);
			}
			
			public boolean freeConseq(int i, int h) {
				if (i + h > height) return false;
				
				for (int j = i; j < i+h; j++) {
					if (col.get(j)) return false; // already occupied
				}
				return true;				
			}
			
			
			public void setOccupied(int i, int h) {
				for (int j = i; j < i+h; j++) {
					col.set(j);
				}
			}
		}

	}
	
}
