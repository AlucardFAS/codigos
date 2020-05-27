package GravityCenter;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

/**
 * @author fernando.silva
 */

// Essa classe é responsável pela leitura do arquivo e tratamento dos dados
public class Reader {
    public static double[][] ReadTxt()throws FileNotFoundException ,IOException {
        
        FileReader file = new FileReader("matriz.txt");
        BufferedReader buffer = new BufferedReader(file);
        String line = buffer.readLine();
        String[] data = line.split(" ");
        int processedData[] = new int[data.length];
        
        // Com as variáveis acima, há um tratamento linha a linha para repassar os dados
        for( int i = 0; i < processedData.length; i++ )
        {
            processedData[i] = Integer.parseInt(data[i]); 
        }
        
        double dataMatrix[][] = new double[processedData[0]][processedData[1]];
        System.out.println(processedData[0]+" "+processedData[1]);
        
        // Printa a matriz completa para visualização dos dados 
        for( int i=0; i < processedData[0]; i++)
        {
            line = buffer.readLine();
            data = line.split(" ");
            for( int j=0; j < processedData[1]; j++ )
            {
                dataMatrix[i][j] = Double.parseDouble(data[j]);
                System.out.print(dataMatrix[i][j]+" ");
            }
        System.out.println("");
        }
        return dataMatrix;
    } 
}