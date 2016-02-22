import java.io.BufferedReader;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;

import edu.wpi.first.wpilibj.networktables.NetworkTable;

public class SendTables {
	public static void main(String[] args) {
		System.out.println("Opening NetworkTables connection...");
		NetworkTable.setClientMode();
		NetworkTable.setIPAddress("10.6.12.21"); //yay
	
		NetworkTable table = NetworkTable.getTable("Vision");
		table.putNumber("Test1", 613); 
		
		System.out.println("Connection aquired, opening file");
		long sleepTime = (long)(((double)1/30) * 1000);
		boolean running = true;
		Path path = FileSystems.getDefault().getPath("C:/vision", "bounding.coordinates");
		
		while (running) {
			try {
				BufferedReader reader = Files.newBufferedReader(path);
				Thread.sleep((long)(sleepTime)); 
				
				double[] coords = processNumArray(reader.readLine());
				table.putNumberArray("BOUNDING_COORDINATES", coords);
				
				for (int i = 0; i < coords.length; i++) {
					System.out.print(coords[i] + " ");
				}
				
				System.out.println();
				
			} catch (Exception e) {
				
			}
		
		}
		
	}
	
	public static double[] processNumArray(String s) {
		s.replaceAll(" ", "");
		String[] sArr = s.split(",");
		double[] dArr = new double[sArr.length];
		
		for (int i = 0; i < dArr.length; i++) {
			dArr[i] = Double.parseDouble(sArr[i]);
		}
		
		return dArr;
	}
}
