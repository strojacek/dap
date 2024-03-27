// Generated from /Users/sethtrojacek/IdeaProjects/jazz/src/main/antlr4/TitleStmt.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class TitleStmtParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

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
		WS=97, COMMENT=98, TITLE=99;
	public static final int
		RULE_title_main = 0, RULE_title_stmt = 1;
	private static String[] makeRuleNames() {
		return new String[] {
			"title_main", "title_stmt"
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
			"RBracket", "WS", "COMMENT", "TITLE"
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
	public String getGrammarFileName() { return "TitleStmt.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public TitleStmtParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Title_mainContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(TitleStmtParser.EOF, 0); }
		public List<Title_stmtContext> title_stmt() {
			return getRuleContexts(Title_stmtContext.class);
		}
		public Title_stmtContext title_stmt(int i) {
			return getRuleContext(Title_stmtContext.class,i);
		}
		public Title_mainContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_title_main; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof TitleStmtListener ) ((TitleStmtListener)listener).enterTitle_main(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof TitleStmtListener ) ((TitleStmtListener)listener).exitTitle_main(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof TitleStmtVisitor ) return ((TitleStmtVisitor<? extends T>)visitor).visitTitle_main(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Title_mainContext title_main() throws RecognitionException {
		Title_mainContext _localctx = new Title_mainContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_title_main);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(7);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==TITLE) {
				{
				{
				setState(4);
				title_stmt();
				}
				}
				setState(9);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(10);
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

	@SuppressWarnings("CheckReturnValue")
	public static class Title_stmtContext extends ParserRuleContext {
		public TerminalNode TITLE() { return getToken(TitleStmtParser.TITLE, 0); }
		public TerminalNode Identifier() { return getToken(TitleStmtParser.Identifier, 0); }
		public TerminalNode SEMICOLON() { return getToken(TitleStmtParser.SEMICOLON, 0); }
		public Title_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_title_stmt; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof TitleStmtListener ) ((TitleStmtListener)listener).enterTitle_stmt(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof TitleStmtListener ) ((TitleStmtListener)listener).exitTitle_stmt(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof TitleStmtVisitor ) return ((TitleStmtVisitor<? extends T>)visitor).visitTitle_stmt(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Title_stmtContext title_stmt() throws RecognitionException {
		Title_stmtContext _localctx = new Title_stmtContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_title_stmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(12);
			match(TITLE);
			setState(13);
			match(Identifier);
			setState(14);
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

	public static final String _serializedATN =
		"\u0004\u0001c\u0011\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0001"+
		"\u0000\u0005\u0000\u0006\b\u0000\n\u0000\f\u0000\t\t\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0000\u0000\u0002\u0000\u0002\u0000\u0000\u000f\u0000\u0007\u0001\u0000"+
		"\u0000\u0000\u0002\f\u0001\u0000\u0000\u0000\u0004\u0006\u0003\u0002\u0001"+
		"\u0000\u0005\u0004\u0001\u0000\u0000\u0000\u0006\t\u0001\u0000\u0000\u0000"+
		"\u0007\u0005\u0001\u0000\u0000\u0000\u0007\b\u0001\u0000\u0000\u0000\b"+
		"\n\u0001\u0000\u0000\u0000\t\u0007\u0001\u0000\u0000\u0000\n\u000b\u0005"+
		"\u0000\u0000\u0001\u000b\u0001\u0001\u0000\u0000\u0000\f\r\u0005c\u0000"+
		"\u0000\r\u000e\u0005M\u0000\u0000\u000e\u000f\u0005.\u0000\u0000\u000f"+
		"\u0003\u0001\u0000\u0000\u0000\u0001\u0007";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}