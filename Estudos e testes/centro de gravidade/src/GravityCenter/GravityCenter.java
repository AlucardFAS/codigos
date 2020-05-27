package GravityCenter;
import static GravityCenter.GravityCenterCalc.*;
import static GravityCenter.Reader.ReadTxt;
import java.io.FileNotFoundException;
import java.io.IOException;

/**
 *
 * @author fernando.silva
 */
public class GravityCenter {    
    public static void main(String[] args)throws FileNotFoundException ,IOException {
        double matrix[][];
        double lineSum[], columnSum[];
        int line, column;
        
        matrix = ReadTxt();
        lineSum = SumLines( matrix );
        columnSum = SumColumns( matrix );
        line = FoundValue( lineSum );
        column = FoundValue( columnSum );
        
        System.out.println("Centro ( "+line+", "+column+" )");
    }   
}