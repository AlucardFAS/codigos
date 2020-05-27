package GravityCenter;

/**
 *
 * @author fernando.silva
 */

// Essa classe é responsável pelos cálculos do centro de gravidade
public class GravityCenterCalc {

    // Este primeiro método auxilia com a soma de linhas da matriz recebida, criando um vetor com a quantidade de linhas
    public static double[] SumLines( double matrix[][] ){

        double line[] = new double[matrix.length];
        
        for( int i = 0; i < matrix.length; i++ )
        {
            for( int j = 0; j < matrix[i].length; j++ )
            {
                line[i] = line[i] + matrix[i][j];
            }
        }
        return line;
    }
    
    // Este segundo método auxilia com a soma de colunas da matriz recebida, criando um vetor com a quantidade de colunas
    public static double[] SumColumns( double matrix[][] ){
        
        double column[] = new double[ matrix[1].length ];

        for( int i = 0; i < matrix[1].length; i++ )
        {
            for( int j = 0; j < matrix.length; j++ )
            {
                column[i] = column[i] + matrix[j][j];
            }
        }
        return column;
    }
    
    // Essa terceira função é responsável por realizar o cálculo conforme descrito no exercício
    public static int FoundValue( double vectorValues[] ){
        double firstValue = 0, secondValue = firstValue, thirdValue = secondValue, limit = 1000;
        int position = 0;
        
        for(int i = 1 ; i < vectorValues.length-1 ; i++)
        {
            for(int j = i - 1; j >= 0; j--) firstValue = firstValue + vectorValues[j];
            for(int j = i+1; j < vectorValues.length; j++) secondValue = secondValue + vectorValues[j];
            
            thirdValue = firstValue - secondValue;

            if(thirdValue < 0) thirdValue = thirdValue * -1;
            if(thirdValue < limit)
            {
                limit = thirdValue;
                position = i;
            }
            firstValue = 0;
            secondValue = 0;
            thirdValue = 0;
        }
        return position + 1;
    }
}