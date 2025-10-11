// Generated from StatComp.g4 by ANTLR 4.13.2
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue", "this-escape"})
public class StatCompLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.13.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, POW=2, ADD=3, SUB=4, MUL=5, DIV=6, INTDIV=7, MOD=8, ASSIGN=9, 
		LPAR=10, RPAR=11, COLON=12, LBRACE=13, RBRACE=14, LBRACK=15, RBRACK=16, 
		COMMA=17, TINT=18, TFLOAT=19, ARRAY=20, ID=21, INT=22, FLOAT=23, WS=24;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "POW", "ADD", "SUB", "MUL", "DIV", "INTDIV", "MOD", "ASSIGN", 
			"LPAR", "RPAR", "COLON", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "COMMA", 
			"TINT", "TFLOAT", "ARRAY", "ID", "INT", "FLOAT", "WS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "';'", "'^'", "'+'", "'-'", "'*'", "'/'", "'//'", "'%'", "'='", 
			"'('", "')'", "':'", "'{'", "'}'", "'['", "']'", "','", "'int'", "'float'", 
			"'array'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, "POW", "ADD", "SUB", "MUL", "DIV", "INTDIV", "MOD", "ASSIGN", 
			"LPAR", "RPAR", "COLON", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "COMMA", 
			"TINT", "TFLOAT", "ARRAY", "ID", "INT", "FLOAT", "WS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public StatCompLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "StatComp.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\u0004\u0000\u0018\u0082\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002"+
		"\u0001\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002"+
		"\u0004\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002"+
		"\u0007\u0007\u0007\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002"+
		"\u000b\u0007\u000b\u0002\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e"+
		"\u0002\u000f\u0007\u000f\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011"+
		"\u0002\u0012\u0007\u0012\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014"+
		"\u0002\u0015\u0007\u0015\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017"+
		"\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0002\u0001\u0002"+
		"\u0001\u0003\u0001\u0003\u0001\u0004\u0001\u0004\u0001\u0005\u0001\u0005"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0007\u0001\u0007\u0001\b\u0001"+
		"\b\u0001\t\u0001\t\u0001\n\u0001\n\u0001\u000b\u0001\u000b\u0001\f\u0001"+
		"\f\u0001\r\u0001\r\u0001\u000e\u0001\u000e\u0001\u000f\u0001\u000f\u0001"+
		"\u0010\u0001\u0010\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001"+
		"\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001"+
		"\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001"+
		"\u0014\u0001\u0014\u0005\u0014g\b\u0014\n\u0014\f\u0014j\t\u0014\u0001"+
		"\u0015\u0004\u0015m\b\u0015\u000b\u0015\f\u0015n\u0001\u0016\u0004\u0016"+
		"r\b\u0016\u000b\u0016\f\u0016s\u0001\u0016\u0001\u0016\u0004\u0016x\b"+
		"\u0016\u000b\u0016\f\u0016y\u0001\u0017\u0004\u0017}\b\u0017\u000b\u0017"+
		"\f\u0017~\u0001\u0017\u0001\u0017\u0000\u0000\u0018\u0001\u0001\u0003"+
		"\u0002\u0005\u0003\u0007\u0004\t\u0005\u000b\u0006\r\u0007\u000f\b\u0011"+
		"\t\u0013\n\u0015\u000b\u0017\f\u0019\r\u001b\u000e\u001d\u000f\u001f\u0010"+
		"!\u0011#\u0012%\u0013\'\u0014)\u0015+\u0016-\u0017/\u0018\u0001\u0000"+
		"\u0004\u0003\u0000AZ__az\u0004\u000009AZ__az\u0001\u000009\u0003\u0000"+
		"\t\n\r\r  \u0086\u0000\u0001\u0001\u0000\u0000\u0000\u0000\u0003\u0001"+
		"\u0000\u0000\u0000\u0000\u0005\u0001\u0000\u0000\u0000\u0000\u0007\u0001"+
		"\u0000\u0000\u0000\u0000\t\u0001\u0000\u0000\u0000\u0000\u000b\u0001\u0000"+
		"\u0000\u0000\u0000\r\u0001\u0000\u0000\u0000\u0000\u000f\u0001\u0000\u0000"+
		"\u0000\u0000\u0011\u0001\u0000\u0000\u0000\u0000\u0013\u0001\u0000\u0000"+
		"\u0000\u0000\u0015\u0001\u0000\u0000\u0000\u0000\u0017\u0001\u0000\u0000"+
		"\u0000\u0000\u0019\u0001\u0000\u0000\u0000\u0000\u001b\u0001\u0000\u0000"+
		"\u0000\u0000\u001d\u0001\u0000\u0000\u0000\u0000\u001f\u0001\u0000\u0000"+
		"\u0000\u0000!\u0001\u0000\u0000\u0000\u0000#\u0001\u0000\u0000\u0000\u0000"+
		"%\u0001\u0000\u0000\u0000\u0000\'\u0001\u0000\u0000\u0000\u0000)\u0001"+
		"\u0000\u0000\u0000\u0000+\u0001\u0000\u0000\u0000\u0000-\u0001\u0000\u0000"+
		"\u0000\u0000/\u0001\u0000\u0000\u0000\u00011\u0001\u0000\u0000\u0000\u0003"+
		"3\u0001\u0000\u0000\u0000\u00055\u0001\u0000\u0000\u0000\u00077\u0001"+
		"\u0000\u0000\u0000\t9\u0001\u0000\u0000\u0000\u000b;\u0001\u0000\u0000"+
		"\u0000\r=\u0001\u0000\u0000\u0000\u000f@\u0001\u0000\u0000\u0000\u0011"+
		"B\u0001\u0000\u0000\u0000\u0013D\u0001\u0000\u0000\u0000\u0015F\u0001"+
		"\u0000\u0000\u0000\u0017H\u0001\u0000\u0000\u0000\u0019J\u0001\u0000\u0000"+
		"\u0000\u001bL\u0001\u0000\u0000\u0000\u001dN\u0001\u0000\u0000\u0000\u001f"+
		"P\u0001\u0000\u0000\u0000!R\u0001\u0000\u0000\u0000#T\u0001\u0000\u0000"+
		"\u0000%X\u0001\u0000\u0000\u0000\'^\u0001\u0000\u0000\u0000)d\u0001\u0000"+
		"\u0000\u0000+l\u0001\u0000\u0000\u0000-q\u0001\u0000\u0000\u0000/|\u0001"+
		"\u0000\u0000\u000012\u0005;\u0000\u00002\u0002\u0001\u0000\u0000\u0000"+
		"34\u0005^\u0000\u00004\u0004\u0001\u0000\u0000\u000056\u0005+\u0000\u0000"+
		"6\u0006\u0001\u0000\u0000\u000078\u0005-\u0000\u00008\b\u0001\u0000\u0000"+
		"\u00009:\u0005*\u0000\u0000:\n\u0001\u0000\u0000\u0000;<\u0005/\u0000"+
		"\u0000<\f\u0001\u0000\u0000\u0000=>\u0005/\u0000\u0000>?\u0005/\u0000"+
		"\u0000?\u000e\u0001\u0000\u0000\u0000@A\u0005%\u0000\u0000A\u0010\u0001"+
		"\u0000\u0000\u0000BC\u0005=\u0000\u0000C\u0012\u0001\u0000\u0000\u0000"+
		"DE\u0005(\u0000\u0000E\u0014\u0001\u0000\u0000\u0000FG\u0005)\u0000\u0000"+
		"G\u0016\u0001\u0000\u0000\u0000HI\u0005:\u0000\u0000I\u0018\u0001\u0000"+
		"\u0000\u0000JK\u0005{\u0000\u0000K\u001a\u0001\u0000\u0000\u0000LM\u0005"+
		"}\u0000\u0000M\u001c\u0001\u0000\u0000\u0000NO\u0005[\u0000\u0000O\u001e"+
		"\u0001\u0000\u0000\u0000PQ\u0005]\u0000\u0000Q \u0001\u0000\u0000\u0000"+
		"RS\u0005,\u0000\u0000S\"\u0001\u0000\u0000\u0000TU\u0005i\u0000\u0000"+
		"UV\u0005n\u0000\u0000VW\u0005t\u0000\u0000W$\u0001\u0000\u0000\u0000X"+
		"Y\u0005f\u0000\u0000YZ\u0005l\u0000\u0000Z[\u0005o\u0000\u0000[\\\u0005"+
		"a\u0000\u0000\\]\u0005t\u0000\u0000]&\u0001\u0000\u0000\u0000^_\u0005"+
		"a\u0000\u0000_`\u0005r\u0000\u0000`a\u0005r\u0000\u0000ab\u0005a\u0000"+
		"\u0000bc\u0005y\u0000\u0000c(\u0001\u0000\u0000\u0000dh\u0007\u0000\u0000"+
		"\u0000eg\u0007\u0001\u0000\u0000fe\u0001\u0000\u0000\u0000gj\u0001\u0000"+
		"\u0000\u0000hf\u0001\u0000\u0000\u0000hi\u0001\u0000\u0000\u0000i*\u0001"+
		"\u0000\u0000\u0000jh\u0001\u0000\u0000\u0000km\u0007\u0002\u0000\u0000"+
		"lk\u0001\u0000\u0000\u0000mn\u0001\u0000\u0000\u0000nl\u0001\u0000\u0000"+
		"\u0000no\u0001\u0000\u0000\u0000o,\u0001\u0000\u0000\u0000pr\u0007\u0002"+
		"\u0000\u0000qp\u0001\u0000\u0000\u0000rs\u0001\u0000\u0000\u0000sq\u0001"+
		"\u0000\u0000\u0000st\u0001\u0000\u0000\u0000tu\u0001\u0000\u0000\u0000"+
		"uw\u0005.\u0000\u0000vx\u0007\u0002\u0000\u0000wv\u0001\u0000\u0000\u0000"+
		"xy\u0001\u0000\u0000\u0000yw\u0001\u0000\u0000\u0000yz\u0001\u0000\u0000"+
		"\u0000z.\u0001\u0000\u0000\u0000{}\u0007\u0003\u0000\u0000|{\u0001\u0000"+
		"\u0000\u0000}~\u0001\u0000\u0000\u0000~|\u0001\u0000\u0000\u0000~\u007f"+
		"\u0001\u0000\u0000\u0000\u007f\u0080\u0001\u0000\u0000\u0000\u0080\u0081"+
		"\u0006\u0017\u0000\u0000\u00810\u0001\u0000\u0000\u0000\u0006\u0000hn"+
		"sy~\u0001\u0006\u0000\u0000";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}