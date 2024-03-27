// Generated from DatalinesLexer.g4 by ANTLR 4.8
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class DatalinesLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		DATALINES=1, CARDS=2, DATALINES4=3, CARDS4=4, WS=5, COMMENT=6, LINE_COMMENT=7, 
		SEMICOLON=8, END_DATALINES4=9, DATALINE=10, DATALINE4=11, TEXT=12;
	public static final int
		DATALINES_MODE=1;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE", "DATALINES_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"DATALINES", "CARDS", "DATALINES4", "CARDS4", "Four", "A", "B", "C", 
			"D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", 
			"R", "S", "T", "U", "V", "W", "X", "Y", "Z", "WS", "COMMENT", "LINE_COMMENT", 
			"SEMICOLON", "END_DATALINES4", "DATALINE", "DATALINE4", "TEXT"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, "';'", "';;;;'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "DATALINES", "CARDS", "DATALINES4", "CARDS4", "WS", "COMMENT", 
			"LINE_COMMENT", "SEMICOLON", "END_DATALINES4", "DATALINE", "DATALINE4", 
			"TEXT"
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


	public DatalinesLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "DatalinesLexer.g4"; }

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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\16\u00f1\b\1\b\1"+
		"\4\2\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t"+
		"\n\4\13\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4"+
		"\22\t\22\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4"+
		"\31\t\31\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4"+
		" \t \4!\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\3\2\3\2\3\2\3"+
		"\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3"+
		"\3\3\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\5\3\5\3"+
		"\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\6\3\6\3\7\3\7\3\b\3\b\3\t\3\t\3\n\3\n"+
		"\3\13\3\13\3\f\3\f\3\r\3\r\3\16\3\16\3\17\3\17\3\20\3\20\3\21\3\21\3\22"+
		"\3\22\3\23\3\23\3\24\3\24\3\25\3\25\3\26\3\26\3\27\3\27\3\30\3\30\3\31"+
		"\3\31\3\32\3\32\3\33\3\33\3\34\3\34\3\35\3\35\3\36\3\36\3\37\3\37\3 \3"+
		" \3!\6!\u00b8\n!\r!\16!\u00b9\3!\3!\3\"\3\"\3\"\3\"\7\"\u00c2\n\"\f\""+
		"\16\"\u00c5\13\"\3\"\3\"\3\"\3\"\3\"\3#\3#\7#\u00ce\n#\f#\16#\u00d1\13"+
		"#\3#\3#\3$\3$\3$\3$\3%\3%\3%\3%\3%\3%\3%\3&\7&\u00e1\n&\f&\16&\u00e4\13"+
		"&\3&\3&\3\'\7\'\u00e9\n\'\f\'\16\'\u00ec\13\'\3\'\3\'\3(\3(\5\u00c3\u00e2"+
		"\u00ea\2)\4\3\6\4\b\5\n\6\f\2\16\2\20\2\22\2\24\2\26\2\30\2\32\2\34\2"+
		"\36\2 \2\"\2$\2&\2(\2*\2,\2.\2\60\2\62\2\64\2\66\28\2:\2<\2>\2@\2B\7D"+
		"\bF\tH\nJ\13L\fN\rP\16\4\2\3\37\4\2CCcc\4\2DDdd\4\2EEee\4\2FFff\4\2GG"+
		"gg\4\2HHhh\4\2IIii\4\2JJjj\4\2KKkk\4\2LLll\4\2MMmm\4\2NNnn\4\2OOoo\4\2"+
		"PPpp\4\2QQqq\4\2RRrr\4\2SSss\4\2TTtt\4\2UUuu\4\2VVvv\4\2WWww\4\2XXxx\4"+
		"\2YYyy\4\2ZZzz\4\2[[{{\4\2\\\\||\5\2\13\f\16\17\"\"\4\2\f\f\17\17\3\2"+
		"==\2\u00d9\2\4\3\2\2\2\2\6\3\2\2\2\2\b\3\2\2\2\2\n\3\2\2\2\2B\3\2\2\2"+
		"\2D\3\2\2\2\2F\3\2\2\2\3H\3\2\2\2\3J\3\2\2\2\3L\3\2\2\2\3N\3\2\2\2\3P"+
		"\3\2\2\2\4R\3\2\2\2\6_\3\2\2\2\bh\3\2\2\2\nv\3\2\2\2\f\u0080\3\2\2\2\16"+
		"\u0082\3\2\2\2\20\u0084\3\2\2\2\22\u0086\3\2\2\2\24\u0088\3\2\2\2\26\u008a"+
		"\3\2\2\2\30\u008c\3\2\2\2\32\u008e\3\2\2\2\34\u0090\3\2\2\2\36\u0092\3"+
		"\2\2\2 \u0094\3\2\2\2\"\u0096\3\2\2\2$\u0098\3\2\2\2&\u009a\3\2\2\2(\u009c"+
		"\3\2\2\2*\u009e\3\2\2\2,\u00a0\3\2\2\2.\u00a2\3\2\2\2\60\u00a4\3\2\2\2"+
		"\62\u00a6\3\2\2\2\64\u00a8\3\2\2\2\66\u00aa\3\2\2\28\u00ac\3\2\2\2:\u00ae"+
		"\3\2\2\2<\u00b0\3\2\2\2>\u00b2\3\2\2\2@\u00b4\3\2\2\2B\u00b7\3\2\2\2D"+
		"\u00bd\3\2\2\2F\u00cb\3\2\2\2H\u00d4\3\2\2\2J\u00d8\3\2\2\2L\u00e2\3\2"+
		"\2\2N\u00ea\3\2\2\2P\u00ef\3\2\2\2RS\5\24\n\2ST\5\16\7\2TU\5\64\32\2U"+
		"V\5\16\7\2VW\5$\22\2WX\5\36\17\2XY\5(\24\2YZ\5\26\13\2Z[\5\62\31\2[\\"+
		"\7=\2\2\\]\3\2\2\2]^\b\2\2\2^\5\3\2\2\2_`\5\22\t\2`a\5\16\7\2ab\5\60\30"+
		"\2bc\5\24\n\2cd\5\62\31\2de\7=\2\2ef\3\2\2\2fg\b\3\2\2g\7\3\2\2\2hi\5"+
		"\24\n\2ij\5\16\7\2jk\5\64\32\2kl\5\16\7\2lm\5$\22\2mn\5\36\17\2no\5(\24"+
		"\2op\5\26\13\2pq\5\62\31\2qr\5\f\6\2rs\7=\2\2st\3\2\2\2tu\b\4\2\2u\t\3"+
		"\2\2\2vw\5\22\t\2wx\5\16\7\2xy\5\60\30\2yz\5\24\n\2z{\5\62\31\2{|\5\f"+
		"\6\2|}\7=\2\2}~\3\2\2\2~\177\b\5\2\2\177\13\3\2\2\2\u0080\u0081\7\66\2"+
		"\2\u0081\r\3\2\2\2\u0082\u0083\t\2\2\2\u0083\17\3\2\2\2\u0084\u0085\t"+
		"\3\2\2\u0085\21\3\2\2\2\u0086\u0087\t\4\2\2\u0087\23\3\2\2\2\u0088\u0089"+
		"\t\5\2\2\u0089\25\3\2\2\2\u008a\u008b\t\6\2\2\u008b\27\3\2\2\2\u008c\u008d"+
		"\t\7\2\2\u008d\31\3\2\2\2\u008e\u008f\t\b\2\2\u008f\33\3\2\2\2\u0090\u0091"+
		"\t\t\2\2\u0091\35\3\2\2\2\u0092\u0093\t\n\2\2\u0093\37\3\2\2\2\u0094\u0095"+
		"\t\13\2\2\u0095!\3\2\2\2\u0096\u0097\t\f\2\2\u0097#\3\2\2\2\u0098\u0099"+
		"\t\r\2\2\u0099%\3\2\2\2\u009a\u009b\t\16\2\2\u009b\'\3\2\2\2\u009c\u009d"+
		"\t\17\2\2\u009d)\3\2\2\2\u009e\u009f\t\20\2\2\u009f+\3\2\2\2\u00a0\u00a1"+
		"\t\21\2\2\u00a1-\3\2\2\2\u00a2\u00a3\t\22\2\2\u00a3/\3\2\2\2\u00a4\u00a5"+
		"\t\23\2\2\u00a5\61\3\2\2\2\u00a6\u00a7\t\24\2\2\u00a7\63\3\2\2\2\u00a8"+
		"\u00a9\t\25\2\2\u00a9\65\3\2\2\2\u00aa\u00ab\t\26\2\2\u00ab\67\3\2\2\2"+
		"\u00ac\u00ad\t\27\2\2\u00ad9\3\2\2\2\u00ae\u00af\t\30\2\2\u00af;\3\2\2"+
		"\2\u00b0\u00b1\t\31\2\2\u00b1=\3\2\2\2\u00b2\u00b3\t\32\2\2\u00b3?\3\2"+
		"\2\2\u00b4\u00b5\t\33\2\2\u00b5A\3\2\2\2\u00b6\u00b8\t\34\2\2\u00b7\u00b6"+
		"\3\2\2\2\u00b8\u00b9\3\2\2\2\u00b9\u00b7\3\2\2\2\u00b9\u00ba\3\2\2\2\u00ba"+
		"\u00bb\3\2\2\2\u00bb\u00bc\b!\3\2\u00bcC\3\2\2\2\u00bd\u00be\7\61\2\2"+
		"\u00be\u00bf\7,\2\2\u00bf\u00c3\3\2\2\2\u00c0\u00c2\13\2\2\2\u00c1\u00c0"+
		"\3\2\2\2\u00c2\u00c5\3\2\2\2\u00c3\u00c4\3\2\2\2\u00c3\u00c1\3\2\2\2\u00c4"+
		"\u00c6\3\2\2\2\u00c5\u00c3\3\2\2\2\u00c6\u00c7\7,\2\2\u00c7\u00c8\7\61"+
		"\2\2\u00c8\u00c9\3\2\2\2\u00c9\u00ca\b\"\3\2\u00caE\3\2\2\2\u00cb\u00cf"+
		"\7,\2\2\u00cc\u00ce\n\35\2\2\u00cd\u00cc\3\2\2\2\u00ce\u00d1\3\2\2\2\u00cf"+
		"\u00cd\3\2\2\2\u00cf\u00d0\3\2\2\2\u00d0\u00d2\3\2\2\2\u00d1\u00cf\3\2"+
		"\2\2\u00d2\u00d3\b#\3\2\u00d3G\3\2\2\2\u00d4\u00d5\7=\2\2\u00d5\u00d6"+
		"\3\2\2\2\u00d6\u00d7\b$\4\2\u00d7I\3\2\2\2\u00d8\u00d9\7=\2\2\u00d9\u00da"+
		"\7=\2\2\u00da\u00db\7=\2\2\u00db\u00dc\7=\2\2\u00dc\u00dd\3\2\2\2\u00dd"+
		"\u00de\b%\4\2\u00deK\3\2\2\2\u00df\u00e1\n\36\2\2\u00e0\u00df\3\2\2\2"+
		"\u00e1\u00e4\3\2\2\2\u00e2\u00e3\3\2\2\2\u00e2\u00e0\3\2\2\2\u00e3\u00e5"+
		"\3\2\2\2\u00e4\u00e2\3\2\2\2\u00e5\u00e6\t\35\2\2\u00e6M\3\2\2\2\u00e7"+
		"\u00e9\13\2\2\2\u00e8\u00e7\3\2\2\2\u00e9\u00ec\3\2\2\2\u00ea\u00eb\3"+
		"\2\2\2\u00ea\u00e8\3\2\2\2\u00eb\u00ed\3\2\2\2\u00ec\u00ea\3\2\2\2\u00ed"+
		"\u00ee\t\35\2\2\u00eeO\3\2\2\2\u00ef\u00f0\13\2\2\2\u00f0Q\3\2\2\2\t\2"+
		"\3\u00b9\u00c3\u00cf\u00e2\u00ea\5\7\3\2\b\2\2\4\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}