import java.io.IOException;
import java.util.Hashtable;


public class Lexer {

  public int line = 1;
  private char peek = ' ';
  private Hashtable words = new Hashtable();

  void reserve(Word t) {
    words.put(t.lexeme, t);
  }

  public Lexer() {
    reserve(new Word(Tag.TRUE, "true"));
    reserve(new Word(Tag.FALSE, "false"));
  }

  public int FloatingPoint(boolean notHavePreviousNumber) throws IOException {
    peek = (char) System.in.read();

    if (notHavePreviousNumber && Character.isDigit(peek) == false)
      { return -1; }

    if (Character.isDigit(peek)) 
    {
      int v = 0;
      do {
        v = 10 * v + Character.digit(peek, 10);
        peek = (char) System.in.read();
      } while (Character.isDigit(peek));
      return v;
    } 
    else 
    {
      return 0;
    }
  }

  public Token Scan() throws IOException {
    
    for (;; peek = (char) System.in.read()) {
      if (peek == ' ' || peek == '\t')
        continue;
      else if (peek == '\n') {
        line = line + 1;
      } else
        break;
    }

    if (Character.isDigit(peek)) {
      int v = 0;
      do {
        v = 10 * v + Character.digit(peek, 10);
        peek = (char) System.in.read();
      } while (Character.isDigit(peek));
      
      
      
      if (peek == '.')
      {
        int floatingNumb = FloatingPoint(false);
        System.out.println(v + "." + floatingNumb);
        return new NumFloat(v, floatingNumb);
      } else {
        System.out.println(v);
        return new Num(v);
      }
    }

    if (peek == '.')
    { 
      int floatingNumb = FloatingPoint(true); 
      
      if (floatingNumb >= 0) {
        System.out.println("0." + floatingNumb);
        return new NumFloat(0, floatingNumb); 
      }
    }

    if (Character.isLetter(peek)) {
      StringBuffer b = new StringBuffer();

      do {
        b.append(peek);
        peek = (char) System.in.read();
      } while (Character.isLetterOrDigit(peek));

      String s = b.toString();
      Word w = (Word) words.get(s);
      
      System.out.println(s);

      if (w != null)
        return w;

      w = new Word(Tag.ID, s);
      words.put(s, w);

      return w;
    }

    Operator o;
    int state = 0;

    while(true)
    {
      if(state != 0)
      {
        peek = (char) System.in.read();
      }

      switch (state) 
      {
        case 0:
          if (peek == '<')
            { state = 1; continue;}
          else if (peek == '=')
            { state = 2; continue;}
          else if (peek == '!')
            { state = 3; continue;}
          else if (peek == '>')
            { state = 4; continue;}
          else 
            break;
        case 1:
          if (peek == '=')
            { System.out.println("LE"); peek = (char) System.in.read(); return o = new Operator(Tag.LE); }
          else { System.out.println("LESSER"); peek = (char) System.in.read(); return o = new Operator(Tag.LESSER); }
        case 2:
          if (peek == '=')
            { System.out.println("EQUAL"); peek = (char) System.in.read(); return o = new Operator(Tag.EQUAL); }
          else
            break;
        case 3:
          if (peek == '=')
            { System.out.println("DIFFERENT"); peek = (char) System.in.read(); return o = new Operator(Tag.DIFFERENT); }
          else
            break;
        case 4:
          if (peek == '=')
          { System.out.println("GE");peek = (char) System.in.read(); return o = new Operator(Tag.GE); }
          else
            { System.out.println("GREATER"); peek = (char) System.in.read(); return o = new Operator(Tag.GREATER); }
      }

      if (state < 1)
        break;
    }

    Comment c;
    state = 0;
    
    while(true){
      
      peek = (char) System.in.read();

      switch (state) 
      {
        case 0:
          if (peek == '/')
            { state = 1; continue;}
          else if (peek == '*')
            { state = 2; continue;}
          else 
            break;
        case 1:
          if (peek == '/')
            { 
              System.out.println("COMMENTLINE");
              return c = new Comment(Tag.COMMENTLINE); 
            }
          else if (peek == '*')
            { 
              System.out.println("INITCOMMENTSTRUCTURE");
              return c = new Comment(Tag.INITCOMMENTSTRUCTURE); 
            }
          else break;
        case 2:
          if (peek == '/')
            { 
              System.out.println("ENDCOMMENTSTRUCTURE");
              return c = new Comment(Tag.ENDCOMMENTSTRUCTURE); 
            } 
          else break;
      }

      if (state < 1)
        break;
    }

    Token t = new Token(peek);
    peek = ' ';
    return t;
  }
}