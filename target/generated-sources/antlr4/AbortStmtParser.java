// Generated from AbortStmt.g4 by ANTLR 4.8
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class AbortStmtParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		ABORT=1, ABEND=2, CANCEL=3, FILE=4, RETURN=5, NOLIST=6, ARRAY=7, ARRAY_NUMERIC_ELEMENTS=8, 
		ARRAY_CHARACTER_ELEMENTS=9, ARRAY_ALL_ELEMENTS=10, BY=11, GROUPFORMAT=12, 
		NOTSORTED=13, DESCENDING=14, CALL=15, DATALINES=16, CARDS=17, LINES=18, 
		DATALINES4=19, CARDS4=20, LINES4=21, END_DATALINES4=22, INFILE=23, DISK=24, 
		DUMMY=25, GTERM=26, PIPE=27, PLOTTER=28, PRINTER=29, TAPE=30, TEMP=31, 
		TERMINAL=32, UPRINTER=33, DSD=34, EXPANDTABS=35, NOEXPANDTABS=36, FLOWOVER=37, 
		MISSOVER=38, PAD=39, NOPAD=40, SCANOVER=41, SHAREBUFFERS=42, STOPOVER=43, 
		TRUNCOVER=44, V_INFILE_=45, SEMICOLON=46, OF=47, EQ=48, NE=49, GT=50, 
		LT=51, GE=52, LE=53, IN=54, EQC=55, NEC=56, GTC=57, LTC=58, GEC=59, LEC=60, 
		INC=61, AND=62, OR=63, NOT=64, MIN=65, MAX=66, DateLiteral=67, TimeLiteral=68, 
		DateTimeLiteral=69, BitLiteral=70, NameLiteral=71, HexLiteral=72, STRINGLITERAL=73, 
		INT=74, MissingValueLiteral=75, FloatingPointLiteral=76, Identifier=77, 
		EQUAL=78, COLON=79, COMMA=80, DOLLAR=81, PERCENT=82, ADD=83, SUB=84, MUL=85, 
		DIV=86, VERLINE=87, EXCLAMATION=88, LParentheses=89, RParentheses=90, 
		LBraces=91, RBraces=92, LSqBracket=93, RSqBracket=94, LBracket=95, RBracket=96, 
		WS=97, COMMENT=98;
	public static final int
		RULE_abort_main = 0, RULE_abort_stmt = 1, RULE_file_spec = 2;
	private static String[] makeRuleNames() {
		return new String[] {
			"abort_main", "abort_stmt", "file_spec"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'abort'", "'abend'", "'cancel'", "'file'", "'return'", "'nolist'", 
			"'array'", "'_NUMERIC_'", "'_CHARACTER_'", "'_ALL_'", "'by'", "'groupformat'", 
			"'notsorted'", "'descending'", "'call'", "'datalines'", "'cards'", "'lines'", 
			"'datalines4'", "'cards4'", "'lines4'", "';;;;'", "'infile'", null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, "';'", null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, "'><'", "'<>'", null, null, null, null, null, null, 
			null, null, "'.'", null, null, "'='", "':'", "','", "'$'", "'%'", "'+'", 
			"'-'", "'*'", "'/'", "'|'", "'!'", "'('", "')'", "'{'", "'}'", "'['", 
			"']'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "ABORT", "ABEND", "CANCEL", "FILE", "RETURN", "NOLIST", "ARRAY", 
			"ARRAY_NUMERIC_ELEMENTS", "ARRAY_CHARACTER_ELEMENTS", "ARRAY_ALL_ELEMENTS", 
			"BY", "GROUPFORMAT", "NOTSORTED", "DESCENDING", "CALL", "DATALINES", 
			"CARDS", "LINES", "DATALINES4", "CARDS4", "LINES4", "END_DATALINES4", 
			"INFILE", "DISK", "DUMMY", "GTERM", "PIPE", "PLOTTER", "PRINTER", "TAPE", 
			"TEMP", "TERMINAL", "UPRINTER", "DSD", "EXPANDTABS", "NOEXPANDTABS", 
			"FLOWOVER", "MISSOVER", "PAD", "NOPAD", "SCANOVER", "SHAREBUFFERS", "STOPOVER", 
			"TRUNCOVER", "V_INFILE_", "SEMICOLON", "OF", "EQ", "NE", "GT", "LT", 
			"GE", "LE", "IN", "EQC", "NEC", "GTC", "LTC", "GEC", "LEC", "INC", "AND", 
			"OR", "NOT", "MIN", "MAX", "DateLiteral", "TimeLiteral", "DateTimeLiteral", 
			"BitLiteral", "NameLiteral", "HexLiteral", "STRINGLITERAL", "INT", "MissingValueLiteral", 
			"FloatingPointLiteral", "Identifier", "EQUAL", "COLON", "COMMA", "DOLLAR", 
			"PERCENT", "ADD", "SUB", "MUL", "DIV", "VERLINE", "EXCLAMATION", "LParentheses", 
			"RParentheses", "LBraces", "RBraces", "LSqBracket", "RSqBracket", "LBracket", 
			"RBracket", "WS", "COMMENT"
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

	@Override
	public String getGrammarFileName() { return "AbortStmt.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public AbortStmtParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class Abort_mainContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(AbortStmtParser.EOF, 0); }
		public List<Abort_stmtContext> abort_stmt() {
			return getRuleContexts(Abort_stmtContext.class);
		}
		public Abort_stmtContext abort_stmt(int i) {
			return getRuleContext(Abort_stmtContext.class,i);
		}
		public Abort_mainContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_abort_main; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof AbortStmtListener ) ((AbortStmtListener)listener).enterAbort_main(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof AbortStmtListener ) ((AbortStmtListener)listener).exitAbort_main(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof AbortStmtVisitor ) return ((AbortStmtVisitor<? extends T>)visitor).visitAbort_main(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Abort_mainContext abort_main() throws RecognitionException {
		Abort_mainContext _localctx = new Abort_mainContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_abort_main);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(9);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==ABORT) {
				{
				{
				setState(6);
				abort_stmt();
				}
				}
				setState(11);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(12);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Abort_stmtContext extends ParserRuleContext {
		public TerminalNode ABORT() { return getToken(AbortStmtParser.ABORT, 0); }
		public TerminalNode SEMICOLON() { return getToken(AbortStmtParser.SEMICOLON, 0); }
		public TerminalNode ABEND() { return getToken(AbortStmtParser.ABEND, 0); }
		public TerminalNode CANCEL() { return getToken(AbortStmtParser.CANCEL, 0); }
		public TerminalNode RETURN() { return getToken(AbortStmtParser.RETURN, 0); }
		public TerminalNode INT() { return getToken(AbortStmtParser.INT, 0); }
		public TerminalNode NOLIST() { return getToken(AbortStmtParser.NOLIST, 0); }
		public File_specContext file_spec() {
			return getRuleContext(File_specContext.class,0);
		}
		public Abort_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_abort_stmt; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof AbortStmtListener ) ((AbortStmtListener)listener).enterAbort_stmt(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof AbortStmtListener ) ((AbortStmtListener)listener).exitAbort_stmt(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof AbortStmtVisitor ) return ((AbortStmtVisitor<? extends T>)visitor).visitAbort_stmt(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Abort_stmtContext abort_stmt() throws RecognitionException {
		Abort_stmtContext _localctx = new Abort_stmtContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_abort_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(14);
			match(ABORT);
			setState(21);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ABEND:
				{
				setState(15);
				match(ABEND);
				}
				break;
			case CANCEL:
				{
				setState(16);
				match(CANCEL);
				setState(18);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==STRINGLITERAL) {
					{
					setState(17);
					file_spec();
					}
				}

				}
				break;
			case RETURN:
				{
				setState(20);
				match(RETURN);
				}
				break;
			case NOLIST:
			case SEMICOLON:
			case INT:
				break;
			default:
				break;
			}
			setState(24);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==INT) {
				{
				setState(23);
				match(INT);
				}
			}

			setState(27);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==NOLIST) {
				{
				setState(26);
				match(NOLIST);
				}
			}

			setState(29);
			match(SEMICOLON);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class File_specContext extends ParserRuleContext {
		public TerminalNode STRINGLITERAL() { return getToken(AbortStmtParser.STRINGLITERAL, 0); }
		public File_specContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_file_spec; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof AbortStmtListener ) ((AbortStmtListener)listener).enterFile_spec(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof AbortStmtListener ) ((AbortStmtListener)listener).exitFile_spec(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof AbortStmtVisitor ) return ((AbortStmtVisitor<? extends T>)visitor).visitFile_spec(this);
			else return visitor.visitChildren(this);
		}
	}

	public final File_specContext file_spec() throws RecognitionException {
		File_specContext _localctx = new File_specContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_file_spec);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(31);
			match(STRINGLITERAL);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3d$\4\2\t\2\4\3\t\3"+
		"\4\4\t\4\3\2\7\2\n\n\2\f\2\16\2\r\13\2\3\2\3\2\3\3\3\3\3\3\3\3\5\3\25"+
		"\n\3\3\3\5\3\30\n\3\3\3\5\3\33\n\3\3\3\5\3\36\n\3\3\3\3\3\3\4\3\4\3\4"+
		"\2\2\5\2\4\6\2\2\2\'\2\13\3\2\2\2\4\20\3\2\2\2\6!\3\2\2\2\b\n\5\4\3\2"+
		"\t\b\3\2\2\2\n\r\3\2\2\2\13\t\3\2\2\2\13\f\3\2\2\2\f\16\3\2\2\2\r\13\3"+
		"\2\2\2\16\17\7\2\2\3\17\3\3\2\2\2\20\27\7\3\2\2\21\30\7\4\2\2\22\24\7"+
		"\5\2\2\23\25\5\6\4\2\24\23\3\2\2\2\24\25\3\2\2\2\25\30\3\2\2\2\26\30\7"+
		"\7\2\2\27\21\3\2\2\2\27\22\3\2\2\2\27\26\3\2\2\2\27\30\3\2\2\2\30\32\3"+
		"\2\2\2\31\33\7L\2\2\32\31\3\2\2\2\32\33\3\2\2\2\33\35\3\2\2\2\34\36\7"+
		"\b\2\2\35\34\3\2\2\2\35\36\3\2\2\2\36\37\3\2\2\2\37 \7\60\2\2 \5\3\2\2"+
		"\2!\"\7K\2\2\"\7\3\2\2\2\7\13\24\27\32\35";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}