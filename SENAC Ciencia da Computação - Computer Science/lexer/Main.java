import java.io.IOException;

public class Main {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		
		Lexer bob = new Lexer();
		//bob.scan();
		
		for(int i = 0; i < 4; i++) {
			System.out.println(bob.Scan().tag);
		}
		
		
	}

}
