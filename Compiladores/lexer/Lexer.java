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

  public Token scan() throws IOException {
    
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

      return new Num(v);
    }

    if (Character.isLetter(peek)) {
      StringBuffer b = new StringBuffer();

      do {
        b.append(peek);
        peek = (char) System.in.read();
      } while (Character.isLetterOrDigit(peek));

      String s = b.toString();
      Word w = (Word) words.get(s);

      if (w != null)
        return w;

      w = new Word(Tag.ID, s);
      words.put(s, w);

      return w;
    }

    Operator o;

    while(true)
    {
      int state = 0;
      
      peek = (char) System.in.read();

      switch (state) 
      {
        case 0:
          if (peek == '<')
            { state = 1; }
          else if (peek == '=')
            { state = 2; }
          else if (peek == '!')
            { state = 3; }
          else if (peek == '>')
            { state = 4; }
          else 
            break;
        case 1:
          if (peek == '=')
            { return o = new Operator(Tag.LE); }
          else { return o = new Operator(Tag.LESSER); }
        case 2:
          if (peek == '=')
            { return o = new Operator(Tag.EQUAL); }
          else
            break;
        case 3:
          if (peek == '=')
            { return o = new Operator(Tag.DIFFERENT); }
          else
            break;
        case 4:
          if (peek == '=')
          { return o = new Operator(Tag.GE); }
          else
            { return o = new Operator(Tag.GREATER); }
      }

      if (state < 1)
        break;
    }

    Comment c;

    while(true){
      int state = 0;
      
      peek = (char) System.in.read();

      switch (state) 
      {
        case 0:
          if (peek == '/')
            { state = 1; }
          else if (peek == '*')
            { state = 2; }
          else 
            break;
        case 1:
          if (peek == '/')
            { 
              line = line - 1;
              return c = new Comment(Tag.COMMENTLINE); 
            }
          else if (peek == '*')
            { return c = new Comment(Tag.INITCOMMENTSTRUCTURE); }
          else 
            break;
        case 2:
          if (peek == '/')
            { return c = new Comment(Tag.ENDCOMMENTSTRUCTURE); } 
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