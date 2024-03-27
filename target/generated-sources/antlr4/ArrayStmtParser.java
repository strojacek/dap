// Generated from ArrayStmt.g4 by ANTLR 4.8
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class ArrayStmtParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, T__16=17, 
		ABEND=18, END=19, LENGTH=20, QKUPCASE=21, SYSEVALF=22, ABORT=23, EVAL=24, 
		LET=25, QSCAN=26, SYSEXEC=27, ACT=28, FILE=29, LIST=30, QSUBSTR=31, SYSFUNC=32, 
		ACTIVATE=33, GLOBAL=34, LISTM=35, QSYSFUNC=36, SYSGET=37, BQUOTE=38, GO=39, 
		LOCAL=40, QUOTE=41, SYSRPUT=42, BY=43, GOTO=44, MACRO=45, QUPCASE=46, 
		THEN=47, CLEAR=48, IF=49, MEND=50, RESOLVE=51, TO=52, CLOSE=53, INC=54, 
		PAUSE=55, RETURN=56, TSO=57, CMS=58, INCLUDE=59, NRSTR=60, RUN=61, UNQUOTE=62, 
		COMANDR=63, INDEX=64, ON=65, SAVE=66, UNSTR=67, COPY=68, INFILE=69, OPEN=70, 
		SCAN=71, UNTIL=72, DEACT=73, INPUT=74, PUT=75, STOP=76, UPCASE=77, DEL=78, 
		KCMPRES=79, NRBQUOTE=80, STR=81, WHILE=82, DELETE=83, KINDEX=84, NRQUOTE=85, 
		SYSCALL=86, WINDOW=87, DISPLAY=88, KLEFT=89, METASYM=90, SUBSTR=91, DMIDSPLY=92, 
		KLENGTH=93, QKCMPRES=94, SUPERQ=95, DMISPLIT=96, KSCAN=97, QKLEFT=98, 
		SYMDEL=99, DO=100, KSUBSTR=101, QKSCAN=102, SYMEXIST=103, EDIT=104, KTRIM=105, 
		QKSUBSTR=106, SYMGLOBL=107, ELSE=108, KUPCASE=109, QKTRIM=110, SYMLOCAL=111, 
		Tk_NULL=112, CANCEL=113, NOLIST=114, ARRAY=115, ARRAY_NUMERIC_ELEMENTS=116, 
		ARRAY_CHARACTER_ELEMENTS=117, ARRAY_ALL_ELEMENTS=118, GROUPFORMAT=119, 
		NOTSORTED=120, DESCENDING=121, CALL=122, DEBUG=123, NESTING=124, STACK=125, 
		READ=126, PW=127, SOURCE=128, VIEW=129, PGM=130, ENCRYPT=131, NOSAVE=132, 
		DATALINES=133, CARDS=134, LINES=135, DATALINES4=136, CARDS4=137, LINES4=138, 
		END_DATALINES4=139, ALTER=140, DISK=141, DUMMY=142, GTERM=143, PIPE=144, 
		PLOTTER=145, PRINTER=146, TAPE=147, TEMP=148, TERMINAL=149, UPRINTER=150, 
		DSD=151, EXPANDTABS=152, NOEXPANDTABS=153, FLOWOVER=154, MISSOVER=155, 
		PAD=156, NOPAD=157, SCANOVER=158, SHAREBUFFERS=159, STOPOVER=160, TRUNCOVER=161, 
		V_INFILE_=162, INPUT_ODS=163, DATE=164, DATETIME=165, DDMMYY=166, INFORMAT_COMMA=167, 
		INFORMAT_CHAR=168, DROP=169, PROC=170, ANOVA=171, MEANS=172, REG=173, 
		CORR=174, SGPLOT=175, PRINT=176, DATA=177, GLM=178, FREQ=179, SQL=180, 
		UNIVARIATE=181, NPAR1WAY=182, IMPORT=183, SORT=184, DATASETS=185, TABULATE=186, 
		RANK=187, CHART=188, LOGISTIC=189, SURVEYSELECT=190, Informat=191, DOLLAR=192, 
		EQ=193, NE=194, GT=195, LT=196, GE=197, LE=198, IN=199, EQC=200, NEC=201, 
		GTC=202, LTC=203, GEC=204, LEC=205, INColon=206, AND=207, OR=208, NOT=209, 
		MIN=210, MAX=211, DateLiteral=212, TimeLiteral=213, DateTimeLiteral=214, 
		BitLiteral=215, NameLiteral=216, HexLiteral=217, STRINGLITERAL=218, INT=219, 
		FloatingPointLiteral=220, Identifier=221, DOT=222, AT=223, EQUAL=224, 
		COMMA=225, LBracket=226, RBracket=227, WS=228, COMMENT=229, LINE_COMMENT=230;
	public static final int
		RULE_array_main = 0, RULE_array_stmt = 1, RULE_array_name = 2, RULE_array_subscript = 3, 
		RULE_array_elements = 4, RULE_initial_value_list = 5, RULE_initial_value_list_item = 6, 
		RULE_initial_value_list_bk = 7, RULE_constant_iter_value = 8, RULE_constant_value = 9, 
		RULE_expression = 10, RULE_expressionList = 11, RULE_of_var_list = 12, 
		RULE_identifiers_list = 13, RULE_in_var_list = 14, RULE_colonInts = 15, 
		RULE_literal = 16, RULE_variables = 17;
	private static String[] makeRuleNames() {
		return new String[] {
			"array_main", "array_stmt", "array_name", "array_subscript", "array_elements", 
			"initial_value_list", "initial_value_list_item", "initial_value_list_bk", 
			"constant_iter_value", "constant_value", "expression", "expressionList", 
			"of_var_list", "identifiers_list", "in_var_list", "colonInts", "literal", 
			"variables"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "';'", "'*'", "':'", "'-'", "'('", "')'", "'{'", "'}'", "'['", 
			"']'", "'**'", "'+'", "'/'", "'%'", "'||'", "'!!'", "'of'", null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, "';;;;'", 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, "'$'", null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, "'><'", "'<>'", 
			null, null, null, null, null, null, null, null, null, null, "'.'", "'@'", 
			"'='", "','"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, "ABEND", "END", "LENGTH", "QKUPCASE", 
			"SYSEVALF", "ABORT", "EVAL", "LET", "QSCAN", "SYSEXEC", "ACT", "FILE", 
			"LIST", "QSUBSTR", "SYSFUNC", "ACTIVATE", "GLOBAL", "LISTM", "QSYSFUNC", 
			"SYSGET", "BQUOTE", "GO", "LOCAL", "QUOTE", "SYSRPUT", "BY", "GOTO", 
			"MACRO", "QUPCASE", "THEN", "CLEAR", "IF", "MEND", "RESOLVE", "TO", "CLOSE", 
			"INC", "PAUSE", "RETURN", "TSO", "CMS", "INCLUDE", "NRSTR", "RUN", "UNQUOTE", 
			"COMANDR", "INDEX", "ON", "SAVE", "UNSTR", "COPY", "INFILE", "OPEN", 
			"SCAN", "UNTIL", "DEACT", "INPUT", "PUT", "STOP", "UPCASE", "DEL", "KCMPRES", 
			"NRBQUOTE", "STR", "WHILE", "DELETE", "KINDEX", "NRQUOTE", "SYSCALL", 
			"WINDOW", "DISPLAY", "KLEFT", "METASYM", "SUBSTR", "DMIDSPLY", "KLENGTH", 
			"QKCMPRES", "SUPERQ", "DMISPLIT", "KSCAN", "QKLEFT", "SYMDEL", "DO", 
			"KSUBSTR", "QKSCAN", "SYMEXIST", "EDIT", "KTRIM", "QKSUBSTR", "SYMGLOBL", 
			"ELSE", "KUPCASE", "QKTRIM", "SYMLOCAL", "Tk_NULL", "CANCEL", "NOLIST", 
			"ARRAY", "ARRAY_NUMERIC_ELEMENTS", "ARRAY_CHARACTER_ELEMENTS", "ARRAY_ALL_ELEMENTS", 
			"GROUPFORMAT", "NOTSORTED", "DESCENDING", "CALL", "DEBUG", "NESTING", 
			"STACK", "READ", "PW", "SOURCE", "VIEW", "PGM", "ENCRYPT", "NOSAVE", 
			"DATALINES", "CARDS", "LINES", "DATALINES4", "CARDS4", "LINES4", "END_DATALINES4", 
			"ALTER", "DISK", "DUMMY", "GTERM", "PIPE", "PLOTTER", "PRINTER", "TAPE", 
			"TEMP", "TERMINAL", "UPRINTER", "DSD", "EXPANDTABS", "NOEXPANDTABS", 
			"FLOWOVER", "MISSOVER", "PAD", "NOPAD", "SCANOVER", "SHAREBUFFERS", "STOPOVER", 
			"TRUNCOVER", "V_INFILE_", "INPUT_ODS", "DATE", "DATETIME", "DDMMYY", 
			"INFORMAT_COMMA", "INFORMAT_CHAR", "DROP", "PROC", "ANOVA", "MEANS", 
			"REG", "CORR", "SGPLOT", "PRINT", "DATA", "GLM", "FREQ", "SQL", "UNIVARIATE", 
			"NPAR1WAY", "IMPORT", "SORT", "DATASETS", "TABULATE", "RANK", "CHART", 
			"LOGISTIC", "SURVEYSELECT", "Informat", "DOLLAR", "EQ", "NE", "GT", "LT", 
			"GE", "LE", "IN", "EQC", "NEC", "GTC", "LTC", "GEC", "LEC", "INColon", 
			"AND", "OR", "NOT", "MIN", "MAX", "DateLiteral", "TimeLiteral", "DateTimeLiteral", 
			"BitLiteral", "NameLiteral", "HexLiteral", "STRINGLITERAL", "INT", "FloatingPointLiteral", 
			"Identifier", "DOT", "AT", "EQUAL", "COMMA", "LBracket", "RBracket", 
			"WS", "COMMENT", "LINE_COMMENT"
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
	public String getGrammarFileName() { return "ArrayStmt.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public ArrayStmtParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class Array_mainContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(ArrayStmtParser.EOF, 0); }
		public List<Array_stmtContext> array_stmt() {
			return getRuleContexts(Array_stmtContext.class);
		}
		public Array_stmtContext array_stmt(int i) {
			return getRuleContext(Array_stmtContext.class,i);
		}
		public Array_mainContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_array_main; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).enterArray_main(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).exitArray_main(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ArrayStmtVisitor ) return ((ArrayStmtVisitor<? extends T>)visitor).visitArray_main(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Array_mainContext array_main() throws RecognitionException {
		Array_mainContext _localctx = new Array_mainContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_array_main);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(39);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==ARRAY) {
				{
				{
				setState(36);
				array_stmt();
				}
				}
				setState(41);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(42);
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

	public static class Array_stmtContext extends ParserRuleContext {
		public TerminalNode ARRAY() { return getToken(ArrayStmtParser.ARRAY, 0); }
		public Array_nameContext array_name() {
			return getRuleContext(Array_nameContext.class,0);
		}
		public TerminalNode LBracket() { return getToken(ArrayStmtParser.LBracket, 0); }
		public Array_subscriptContext array_subscript() {
			return getRuleContext(Array_subscriptContext.class,0);
		}
		public TerminalNode RBracket() { return getToken(ArrayStmtParser.RBracket, 0); }
		public TerminalNode DOLLAR() { return getToken(ArrayStmtParser.DOLLAR, 0); }
		public TerminalNode INT() { return getToken(ArrayStmtParser.INT, 0); }
		public Array_elementsContext array_elements() {
			return getRuleContext(Array_elementsContext.class,0);
		}
		public Initial_value_listContext initial_value_list() {
			return getRuleContext(Initial_value_listContext.class,0);
		}
		public Array_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_array_stmt; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).enterArray_stmt(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).exitArray_stmt(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ArrayStmtVisitor ) return ((ArrayStmtVisitor<? extends T>)visitor).visitArray_stmt(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Array_stmtContext array_stmt() throws RecognitionException {
		Array_stmtContext _localctx = new Array_stmtContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_array_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(44);
			match(ARRAY);
			setState(45);
			array_name();
			setState(46);
			match(LBracket);
			setState(47);
			array_subscript();
			setState(48);
			match(RBracket);
			setState(50);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==DOLLAR) {
				{
				setState(49);
				match(DOLLAR);
				}
			}

			setState(53);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==INT) {
				{
				setState(52);
				match(INT);
				}
			}

			setState(56);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (((((_la - 116)) & ~0x3f) == 0 && ((1L << (_la - 116)) & ((1L << (ARRAY_NUMERIC_ELEMENTS - 116)) | (1L << (ARRAY_CHARACTER_ELEMENTS - 116)) | (1L << (ARRAY_ALL_ELEMENTS - 116)))) != 0) || _la==Identifier) {
				{
				setState(55);
				array_elements();
				}
			}

			setState(59);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==T__4) {
				{
				setState(58);
				initial_value_list();
				}
			}

			setState(61);
			match(T__0);
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

	public static class Array_nameContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(ArrayStmtParser.Identifier, 0); }
		public Array_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_array_name; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).enterArray_name(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).exitArray_name(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ArrayStmtVisitor ) return ((ArrayStmtVisitor<? extends T>)visitor).visitArray_name(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Array_nameContext array_name() throws RecognitionException {
		Array_nameContext _localctx = new Array_nameContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_array_name);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(63);
			match(Identifier);
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

	public static class Array_subscriptContext extends ParserRuleContext {
		public List<TerminalNode> INT() { return getTokens(ArrayStmtParser.INT); }
		public TerminalNode INT(int i) {
			return getToken(ArrayStmtParser.INT, i);
		}
		public List<TerminalNode> COMMA() { return getTokens(ArrayStmtParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(ArrayStmtParser.COMMA, i);
		}
		public Array_subscriptContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_array_subscript; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).enterArray_subscript(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).exitArray_subscript(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ArrayStmtVisitor ) return ((ArrayStmtVisitor<? extends T>)visitor).visitArray_subscript(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Array_subscriptContext array_subscript() throws RecognitionException {
		Array_subscriptContext _localctx = new Array_subscriptContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_array_subscript);
		int _la;
		try {
			setState(86);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(65);
				match(T__1);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(66);
				match(INT);
				setState(71);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMMA) {
					{
					{
					setState(67);
					match(COMMA);
					setState(68);
					match(INT);
					}
					}
					setState(73);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(74);
				match(INT);
				setState(75);
				match(T__2);
				setState(76);
				match(INT);
				setState(83);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMMA) {
					{
					{
					setState(77);
					match(COMMA);
					setState(78);
					match(INT);
					setState(79);
					match(T__2);
					setState(80);
					match(INT);
					}
					}
					setState(85);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				break;
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

	public static class Array_elementsContext extends ParserRuleContext {
		public TerminalNode ARRAY_NUMERIC_ELEMENTS() { return getToken(ArrayStmtParser.ARRAY_NUMERIC_ELEMENTS, 0); }
		public TerminalNode ARRAY_CHARACTER_ELEMENTS() { return getToken(ArrayStmtParser.ARRAY_CHARACTER_ELEMENTS, 0); }
		public TerminalNode ARRAY_ALL_ELEMENTS() { return getToken(ArrayStmtParser.ARRAY_ALL_ELEMENTS, 0); }
		public List<TerminalNode> Identifier() { return getTokens(ArrayStmtParser.Identifier); }
		public TerminalNode Identifier(int i) {
			return getToken(ArrayStmtParser.Identifier, i);
		}
		public Array_elementsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_array_elements; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).enterArray_elements(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).exitArray_elements(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ArrayStmtVisitor ) return ((ArrayStmtVisitor<? extends T>)visitor).visitArray_elements(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Array_elementsContext array_elements() throws RecognitionException {
		Array_elementsContext _localctx = new Array_elementsContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_array_elements);
		int _la;
		try {
			setState(99);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(88);
				match(ARRAY_NUMERIC_ELEMENTS);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(89);
				match(ARRAY_CHARACTER_ELEMENTS);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(90);
				match(ARRAY_ALL_ELEMENTS);
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(92); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(91);
					match(Identifier);
					}
					}
					setState(94); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==Identifier );
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(96);
				match(Identifier);
				setState(97);
				match(T__3);
				setState(98);
				match(Identifier);
				}
				break;
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

	public static class Initial_value_listContext extends ParserRuleContext {
		public List<Initial_value_list_itemContext> initial_value_list_item() {
			return getRuleContexts(Initial_value_list_itemContext.class);
		}
		public Initial_value_list_itemContext initial_value_list_item(int i) {
			return getRuleContext(Initial_value_list_itemContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(ArrayStmtParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(ArrayStmtParser.COMMA, i);
		}
		public Initial_value_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_initial_value_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).enterInitial_value_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).exitInitial_value_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ArrayStmtVisitor ) return ((ArrayStmtVisitor<? extends T>)visitor).visitInitial_value_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Initial_value_listContext initial_value_list() throws RecognitionException {
		Initial_value_listContext _localctx = new Initial_value_listContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_initial_value_list);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(101);
			match(T__4);
			{
			setState(102);
			initial_value_list_item();
			}
			setState(109);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (((((_la - 218)) & ~0x3f) == 0 && ((1L << (_la - 218)) & ((1L << (STRINGLITERAL - 218)) | (1L << (INT - 218)) | (1L << (FloatingPointLiteral - 218)) | (1L << (COMMA - 218)))) != 0)) {
				{
				{
				setState(104);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==COMMA) {
					{
					setState(103);
					match(COMMA);
					}
				}

				setState(106);
				initial_value_list_item();
				}
				}
				setState(111);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(112);
			match(T__5);
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

	public static class Initial_value_list_itemContext extends ParserRuleContext {
		public List<TerminalNode> INT() { return getTokens(ArrayStmtParser.INT); }
		public TerminalNode INT(int i) {
			return getToken(ArrayStmtParser.INT, i);
		}
		public Constant_iter_valueContext constant_iter_value() {
			return getRuleContext(Constant_iter_valueContext.class,0);
		}
		public Initial_value_listContext initial_value_list() {
			return getRuleContext(Initial_value_listContext.class,0);
		}
		public Constant_valueContext constant_value() {
			return getRuleContext(Constant_valueContext.class,0);
		}
		public Initial_value_list_itemContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_initial_value_list_item; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).enterInitial_value_list_item(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).exitInitial_value_list_item(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ArrayStmtVisitor ) return ((ArrayStmtVisitor<? extends T>)visitor).visitInitial_value_list_item(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Initial_value_list_itemContext initial_value_list_item() throws RecognitionException {
		Initial_value_list_itemContext _localctx = new Initial_value_list_itemContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_initial_value_list_item);
		try {
			setState(126);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,12,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(114);
				match(INT);
				setState(115);
				match(T__2);
				setState(116);
				match(INT);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(117);
				constant_iter_value();
				setState(118);
				match(T__1);
				setState(119);
				initial_value_list();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(121);
				constant_iter_value();
				setState(122);
				match(T__1);
				setState(123);
				constant_value();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(125);
				constant_value();
				}
				break;
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

	public static class Initial_value_list_bkContext extends ParserRuleContext {
		public List<Constant_valueContext> constant_value() {
			return getRuleContexts(Constant_valueContext.class);
		}
		public Constant_valueContext constant_value(int i) {
			return getRuleContext(Constant_valueContext.class,i);
		}
		public List<Constant_iter_valueContext> constant_iter_value() {
			return getRuleContexts(Constant_iter_valueContext.class);
		}
		public Constant_iter_valueContext constant_iter_value(int i) {
			return getRuleContext(Constant_iter_valueContext.class,i);
		}
		public List<Initial_value_listContext> initial_value_list() {
			return getRuleContexts(Initial_value_listContext.class);
		}
		public Initial_value_listContext initial_value_list(int i) {
			return getRuleContext(Initial_value_listContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(ArrayStmtParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(ArrayStmtParser.COMMA, i);
		}
		public Initial_value_list_bkContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_initial_value_list_bk; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).enterInitial_value_list_bk(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).exitInitial_value_list_bk(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ArrayStmtVisitor ) return ((ArrayStmtVisitor<? extends T>)visitor).visitInitial_value_list_bk(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Initial_value_list_bkContext initial_value_list_bk() throws RecognitionException {
		Initial_value_list_bkContext _localctx = new Initial_value_list_bkContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_initial_value_list_bk);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(128);
			match(T__4);
			setState(138);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
			case 1:
				{
				{
				setState(129);
				constant_iter_value();
				setState(130);
				match(T__1);
				setState(131);
				initial_value_list();
				}
				}
				break;
			case 2:
				{
				{
				setState(133);
				constant_iter_value();
				setState(134);
				match(T__1);
				setState(135);
				constant_value();
				}
				}
				break;
			case 3:
				{
				setState(137);
				constant_value();
				}
				break;
			}
			setState(156);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (((((_la - 218)) & ~0x3f) == 0 && ((1L << (_la - 218)) & ((1L << (STRINGLITERAL - 218)) | (1L << (INT - 218)) | (1L << (FloatingPointLiteral - 218)) | (1L << (COMMA - 218)))) != 0)) {
				{
				{
				setState(141);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==COMMA) {
					{
					setState(140);
					match(COMMA);
					}
				}

				setState(152);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
				case 1:
					{
					{
					setState(143);
					constant_iter_value();
					setState(144);
					match(T__1);
					setState(145);
					initial_value_list();
					}
					}
					break;
				case 2:
					{
					{
					setState(147);
					constant_iter_value();
					setState(148);
					match(T__1);
					setState(149);
					constant_value();
					}
					}
					break;
				case 3:
					{
					setState(151);
					constant_value();
					}
					break;
				}
				}
				}
				setState(158);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(159);
			match(T__5);
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

	public static class Constant_iter_valueContext extends ParserRuleContext {
		public TerminalNode INT() { return getToken(ArrayStmtParser.INT, 0); }
		public Constant_iter_valueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constant_iter_value; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).enterConstant_iter_value(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).exitConstant_iter_value(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ArrayStmtVisitor ) return ((ArrayStmtVisitor<? extends T>)visitor).visitConstant_iter_value(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Constant_iter_valueContext constant_iter_value() throws RecognitionException {
		Constant_iter_valueContext _localctx = new Constant_iter_valueContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_constant_iter_value);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(161);
			match(INT);
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

	public static class Constant_valueContext extends ParserRuleContext {
		public TerminalNode INT() { return getToken(ArrayStmtParser.INT, 0); }
		public TerminalNode FloatingPointLiteral() { return getToken(ArrayStmtParser.FloatingPointLiteral, 0); }
		public TerminalNode STRINGLITERAL() { return getToken(ArrayStmtParser.STRINGLITERAL, 0); }
		public Constant_valueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constant_value; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).enterConstant_value(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).exitConstant_value(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ArrayStmtVisitor ) return ((ArrayStmtVisitor<? extends T>)visitor).visitConstant_value(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Constant_valueContext constant_value() throws RecognitionException {
		Constant_valueContext _localctx = new Constant_valueContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_constant_value);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(163);
			_la = _input.LA(1);
			if ( !(((((_la - 218)) & ~0x3f) == 0 && ((1L << (_la - 218)) & ((1L << (STRINGLITERAL - 218)) | (1L << (INT - 218)) | (1L << (FloatingPointLiteral - 218)))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
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

	public static class ExpressionContext extends ParserRuleContext {
		public LiteralContext literal() {
			return getRuleContext(LiteralContext.class,0);
		}
		public TerminalNode Identifier() { return getToken(ArrayStmtParser.Identifier, 0); }
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode NOT() { return getToken(ArrayStmtParser.NOT, 0); }
		public TerminalNode MIN() { return getToken(ArrayStmtParser.MIN, 0); }
		public TerminalNode MAX() { return getToken(ArrayStmtParser.MAX, 0); }
		public TerminalNode EQ() { return getToken(ArrayStmtParser.EQ, 0); }
		public TerminalNode NE() { return getToken(ArrayStmtParser.NE, 0); }
		public TerminalNode GT() { return getToken(ArrayStmtParser.GT, 0); }
		public TerminalNode LT() { return getToken(ArrayStmtParser.LT, 0); }
		public TerminalNode GE() { return getToken(ArrayStmtParser.GE, 0); }
		public TerminalNode LE() { return getToken(ArrayStmtParser.LE, 0); }
		public TerminalNode EQC() { return getToken(ArrayStmtParser.EQC, 0); }
		public TerminalNode NEC() { return getToken(ArrayStmtParser.NEC, 0); }
		public TerminalNode GTC() { return getToken(ArrayStmtParser.GTC, 0); }
		public TerminalNode LTC() { return getToken(ArrayStmtParser.LTC, 0); }
		public TerminalNode GEC() { return getToken(ArrayStmtParser.GEC, 0); }
		public TerminalNode LEC() { return getToken(ArrayStmtParser.LEC, 0); }
		public TerminalNode AND() { return getToken(ArrayStmtParser.AND, 0); }
		public TerminalNode OR() { return getToken(ArrayStmtParser.OR, 0); }
		public TerminalNode EQUAL() { return getToken(ArrayStmtParser.EQUAL, 0); }
		public ExpressionListContext expressionList() {
			return getRuleContext(ExpressionListContext.class,0);
		}
		public In_var_listContext in_var_list() {
			return getRuleContext(In_var_listContext.class,0);
		}
		public TerminalNode IN() { return getToken(ArrayStmtParser.IN, 0); }
		public TerminalNode INColon() { return getToken(ArrayStmtParser.INColon, 0); }
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).enterExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).exitExpression(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ArrayStmtVisitor ) return ((ArrayStmtVisitor<? extends T>)visitor).visitExpression(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ExpressionContext expression() throws RecognitionException {
		return expression(0);
	}

	private ExpressionContext expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExpressionContext _localctx = new ExpressionContext(_ctx, _parentState);
		ExpressionContext _prevctx = _localctx;
		int _startState = 20;
		enterRecursionRule(_localctx, 20, RULE_expression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(176);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case DateLiteral:
			case TimeLiteral:
			case DateTimeLiteral:
			case BitLiteral:
			case NameLiteral:
			case HexLiteral:
			case STRINGLITERAL:
			case INT:
			case FloatingPointLiteral:
			case DOT:
				{
				setState(166);
				literal();
				}
				break;
			case Identifier:
				{
				setState(167);
				match(Identifier);
				}
				break;
			case T__4:
				{
				setState(168);
				match(T__4);
				setState(169);
				expression(0);
				setState(170);
				match(T__5);
				}
				break;
			case T__3:
			case T__11:
				{
				setState(172);
				_la = _input.LA(1);
				if ( !(_la==T__3 || _la==T__11) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(173);
				expression(12);
				}
				break;
			case NOT:
				{
				setState(174);
				match(NOT);
				setState(175);
				expression(11);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(229);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(227);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,19,_ctx) ) {
					case 1:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(178);
						if (!(precpred(_ctx, 13))) throw new FailedPredicateException(this, "precpred(_ctx, 13)");
						setState(179);
						match(T__10);
						setState(180);
						expression(13);
						}
						break;
					case 2:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(181);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(182);
						match(MIN);
						setState(183);
						expression(11);
						}
						break;
					case 3:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(184);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(185);
						match(MAX);
						setState(186);
						expression(10);
						}
						break;
					case 4:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(187);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(188);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__1) | (1L << T__12) | (1L << T__13))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(189);
						expression(9);
						}
						break;
					case 5:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(190);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(191);
						_la = _input.LA(1);
						if ( !(_la==T__3 || _la==T__11) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(192);
						expression(8);
						}
						break;
					case 6:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(193);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(194);
						_la = _input.LA(1);
						if ( !(_la==T__14 || _la==T__15) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(195);
						expression(7);
						}
						break;
					case 7:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(196);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(197);
						_la = _input.LA(1);
						if ( !(((((_la - 193)) & ~0x3f) == 0 && ((1L << (_la - 193)) & ((1L << (EQ - 193)) | (1L << (NE - 193)) | (1L << (GT - 193)) | (1L << (LT - 193)) | (1L << (GE - 193)) | (1L << (LE - 193)))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(198);
						expression(6);
						}
						break;
					case 8:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(199);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(200);
						_la = _input.LA(1);
						if ( !(((((_la - 200)) & ~0x3f) == 0 && ((1L << (_la - 200)) & ((1L << (EQC - 200)) | (1L << (NEC - 200)) | (1L << (GTC - 200)) | (1L << (LTC - 200)) | (1L << (GEC - 200)) | (1L << (LEC - 200)))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(201);
						expression(5);
						}
						break;
					case 9:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(202);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(203);
						_la = _input.LA(1);
						if ( !(_la==AND || _la==OR) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(204);
						expression(3);
						}
						break;
					case 10:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(205);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(206);
						match(EQUAL);
						setState(207);
						expression(1);
						}
						break;
					case 11:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(208);
						if (!(precpred(_ctx, 16))) throw new FailedPredicateException(this, "precpred(_ctx, 16)");
						setState(209);
						match(T__4);
						setState(211);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__3) | (1L << T__4) | (1L << T__11) | (1L << T__16))) != 0) || ((((_la - 209)) & ~0x3f) == 0 && ((1L << (_la - 209)) & ((1L << (NOT - 209)) | (1L << (DateLiteral - 209)) | (1L << (TimeLiteral - 209)) | (1L << (DateTimeLiteral - 209)) | (1L << (BitLiteral - 209)) | (1L << (NameLiteral - 209)) | (1L << (HexLiteral - 209)) | (1L << (STRINGLITERAL - 209)) | (1L << (INT - 209)) | (1L << (FloatingPointLiteral - 209)) | (1L << (Identifier - 209)) | (1L << (DOT - 209)))) != 0)) {
							{
							setState(210);
							expressionList(0);
							}
						}

						setState(213);
						match(T__5);
						}
						break;
					case 12:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(214);
						if (!(precpred(_ctx, 15))) throw new FailedPredicateException(this, "precpred(_ctx, 15)");
						setState(215);
						match(T__6);
						setState(216);
						expression(0);
						setState(217);
						match(T__7);
						}
						break;
					case 13:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(219);
						if (!(precpred(_ctx, 14))) throw new FailedPredicateException(this, "precpred(_ctx, 14)");
						setState(220);
						match(T__8);
						setState(221);
						expression(0);
						setState(222);
						match(T__9);
						}
						break;
					case 14:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(224);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(225);
						_la = _input.LA(1);
						if ( !(_la==IN || _la==INColon) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(226);
						in_var_list();
						}
						break;
					}
					} 
				}
				setState(231);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class ExpressionListContext extends ParserRuleContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<Of_var_listContext> of_var_list() {
			return getRuleContexts(Of_var_listContext.class);
		}
		public Of_var_listContext of_var_list(int i) {
			return getRuleContext(Of_var_listContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(ArrayStmtParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(ArrayStmtParser.COMMA, i);
		}
		public List<ExpressionListContext> expressionList() {
			return getRuleContexts(ExpressionListContext.class);
		}
		public ExpressionListContext expressionList(int i) {
			return getRuleContext(ExpressionListContext.class,i);
		}
		public ExpressionListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expressionList; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).enterExpressionList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).exitExpressionList(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ArrayStmtVisitor ) return ((ArrayStmtVisitor<? extends T>)visitor).visitExpressionList(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ExpressionListContext expressionList() throws RecognitionException {
		return expressionList(0);
	}

	private ExpressionListContext expressionList(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExpressionListContext _localctx = new ExpressionListContext(_ctx, _parentState);
		ExpressionListContext _prevctx = _localctx;
		int _startState = 22;
		enterRecursionRule(_localctx, 22, RULE_expressionList, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(235);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__3:
			case T__4:
			case T__11:
			case NOT:
			case DateLiteral:
			case TimeLiteral:
			case DateTimeLiteral:
			case BitLiteral:
			case NameLiteral:
			case HexLiteral:
			case STRINGLITERAL:
			case INT:
			case FloatingPointLiteral:
			case Identifier:
			case DOT:
				{
				setState(233);
				expression(0);
				}
				break;
			case T__16:
				{
				setState(234);
				of_var_list();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(244);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(237);
					match(COMMA);
					setState(240);
					_errHandler.sync(this);
					switch (_input.LA(1)) {
					case T__3:
					case T__4:
					case T__11:
					case NOT:
					case DateLiteral:
					case TimeLiteral:
					case DateTimeLiteral:
					case BitLiteral:
					case NameLiteral:
					case HexLiteral:
					case STRINGLITERAL:
					case INT:
					case FloatingPointLiteral:
					case Identifier:
					case DOT:
						{
						setState(238);
						expression(0);
						}
						break;
					case T__16:
						{
						setState(239);
						of_var_list();
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					}
					} 
				}
				setState(246);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
			}
			}
			_ctx.stop = _input.LT(-1);
			setState(256);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,25,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ExpressionListContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_expressionList);
					setState(247);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(249); 
					_errHandler.sync(this);
					_la = _input.LA(1);
					do {
						{
						{
						setState(248);
						match(COMMA);
						}
						}
						setState(251); 
						_errHandler.sync(this);
						_la = _input.LA(1);
					} while ( _la==COMMA );
					setState(253);
					expressionList(2);
					}
					} 
				}
				setState(258);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,25,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class Of_var_listContext extends ParserRuleContext {
		public List<TerminalNode> Identifier() { return getTokens(ArrayStmtParser.Identifier); }
		public TerminalNode Identifier(int i) {
			return getToken(ArrayStmtParser.Identifier, i);
		}
		public List<TerminalNode> COMMA() { return getTokens(ArrayStmtParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(ArrayStmtParser.COMMA, i);
		}
		public Of_var_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_of_var_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).enterOf_var_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).exitOf_var_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ArrayStmtVisitor ) return ((ArrayStmtVisitor<? extends T>)visitor).visitOf_var_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Of_var_listContext of_var_list() throws RecognitionException {
		Of_var_listContext _localctx = new Of_var_listContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_of_var_list);
		int _la;
		try {
			int _alt;
			setState(289);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,29,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(259);
				match(T__16);
				{
				setState(260);
				match(Identifier);
				setState(261);
				match(T__3);
				setState(262);
				match(Identifier);
				}
				setState(273);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,27,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(266);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if (_la==COMMA) {
							{
							setState(264);
							match(COMMA);
							setState(265);
							match(T__16);
							}
						}

						{
						setState(268);
						match(Identifier);
						setState(269);
						match(T__3);
						setState(270);
						match(Identifier);
						}
						}
						} 
					}
					setState(275);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,27,_ctx);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(276);
				match(T__16);
				setState(277);
				match(Identifier);
				setState(281);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,28,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(278);
						match(Identifier);
						}
						} 
					}
					setState(283);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,28,_ctx);
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(284);
				match(T__16);
				setState(285);
				match(Identifier);
				setState(286);
				match(T__8);
				setState(287);
				match(T__1);
				setState(288);
				match(T__9);
				}
				break;
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

	public static class Identifiers_listContext extends ParserRuleContext {
		public List<TerminalNode> Identifier() { return getTokens(ArrayStmtParser.Identifier); }
		public TerminalNode Identifier(int i) {
			return getToken(ArrayStmtParser.Identifier, i);
		}
		public Identifiers_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_identifiers_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).enterIdentifiers_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).exitIdentifiers_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ArrayStmtVisitor ) return ((ArrayStmtVisitor<? extends T>)visitor).visitIdentifiers_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Identifiers_listContext identifiers_list() throws RecognitionException {
		Identifiers_listContext _localctx = new Identifiers_listContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_identifiers_list);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(295); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				setState(295);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,30,_ctx) ) {
				case 1:
					{
					setState(291);
					match(Identifier);
					}
					break;
				case 2:
					{
					setState(292);
					match(Identifier);
					setState(293);
					match(T__3);
					setState(294);
					match(Identifier);
					}
					break;
				}
				}
				setState(297); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==Identifier );
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

	public static class In_var_listContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(ArrayStmtParser.Identifier, 0); }
		public List<LiteralContext> literal() {
			return getRuleContexts(LiteralContext.class);
		}
		public LiteralContext literal(int i) {
			return getRuleContext(LiteralContext.class,i);
		}
		public List<ColonIntsContext> colonInts() {
			return getRuleContexts(ColonIntsContext.class);
		}
		public ColonIntsContext colonInts(int i) {
			return getRuleContext(ColonIntsContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(ArrayStmtParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(ArrayStmtParser.COMMA, i);
		}
		public In_var_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_in_var_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).enterIn_var_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).exitIn_var_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ArrayStmtVisitor ) return ((ArrayStmtVisitor<? extends T>)visitor).visitIn_var_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final In_var_listContext in_var_list() throws RecognitionException {
		In_var_listContext _localctx = new In_var_listContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_in_var_list);
		int _la;
		try {
			setState(317);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Identifier:
				enterOuterAlt(_localctx, 1);
				{
				setState(299);
				match(Identifier);
				}
				break;
			case T__4:
				enterOuterAlt(_localctx, 2);
				{
				setState(300);
				match(T__4);
				setState(303);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,32,_ctx) ) {
				case 1:
					{
					setState(301);
					literal();
					}
					break;
				case 2:
					{
					setState(302);
					colonInts();
					}
					break;
				}
				setState(312);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMMA) {
					{
					{
					setState(305);
					match(COMMA);
					setState(308);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,33,_ctx) ) {
					case 1:
						{
						setState(306);
						literal();
						}
						break;
					case 2:
						{
						setState(307);
						colonInts();
						}
						break;
					}
					}
					}
					setState(314);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(315);
				match(T__5);
				}
				break;
			default:
				throw new NoViableAltException(this);
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

	public static class ColonIntsContext extends ParserRuleContext {
		public List<TerminalNode> INT() { return getTokens(ArrayStmtParser.INT); }
		public TerminalNode INT(int i) {
			return getToken(ArrayStmtParser.INT, i);
		}
		public ColonIntsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_colonInts; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).enterColonInts(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).exitColonInts(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ArrayStmtVisitor ) return ((ArrayStmtVisitor<? extends T>)visitor).visitColonInts(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ColonIntsContext colonInts() throws RecognitionException {
		ColonIntsContext _localctx = new ColonIntsContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_colonInts);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(319);
			match(INT);
			setState(320);
			match(T__2);
			setState(321);
			match(INT);
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

	public static class LiteralContext extends ParserRuleContext {
		public TerminalNode INT() { return getToken(ArrayStmtParser.INT, 0); }
		public TerminalNode FloatingPointLiteral() { return getToken(ArrayStmtParser.FloatingPointLiteral, 0); }
		public TerminalNode STRINGLITERAL() { return getToken(ArrayStmtParser.STRINGLITERAL, 0); }
		public TerminalNode DateLiteral() { return getToken(ArrayStmtParser.DateLiteral, 0); }
		public TerminalNode TimeLiteral() { return getToken(ArrayStmtParser.TimeLiteral, 0); }
		public TerminalNode DateTimeLiteral() { return getToken(ArrayStmtParser.DateTimeLiteral, 0); }
		public TerminalNode BitLiteral() { return getToken(ArrayStmtParser.BitLiteral, 0); }
		public TerminalNode NameLiteral() { return getToken(ArrayStmtParser.NameLiteral, 0); }
		public TerminalNode HexLiteral() { return getToken(ArrayStmtParser.HexLiteral, 0); }
		public TerminalNode DOT() { return getToken(ArrayStmtParser.DOT, 0); }
		public LiteralContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_literal; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).enterLiteral(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).exitLiteral(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ArrayStmtVisitor ) return ((ArrayStmtVisitor<? extends T>)visitor).visitLiteral(this);
			else return visitor.visitChildren(this);
		}
	}

	public final LiteralContext literal() throws RecognitionException {
		LiteralContext _localctx = new LiteralContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_literal);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(323);
			_la = _input.LA(1);
			if ( !(((((_la - 212)) & ~0x3f) == 0 && ((1L << (_la - 212)) & ((1L << (DateLiteral - 212)) | (1L << (TimeLiteral - 212)) | (1L << (DateTimeLiteral - 212)) | (1L << (BitLiteral - 212)) | (1L << (NameLiteral - 212)) | (1L << (HexLiteral - 212)) | (1L << (STRINGLITERAL - 212)) | (1L << (INT - 212)) | (1L << (FloatingPointLiteral - 212)) | (1L << (DOT - 212)))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
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

	public static class VariablesContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(ArrayStmtParser.Identifier, 0); }
		public TerminalNode DATE() { return getToken(ArrayStmtParser.DATE, 0); }
		public TerminalNode ALTER() { return getToken(ArrayStmtParser.ALTER, 0); }
		public TerminalNode DROP() { return getToken(ArrayStmtParser.DROP, 0); }
		public List<VariablesContext> variables() {
			return getRuleContexts(VariablesContext.class);
		}
		public VariablesContext variables(int i) {
			return getRuleContext(VariablesContext.class,i);
		}
		public TerminalNode DOT() { return getToken(ArrayStmtParser.DOT, 0); }
		public VariablesContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variables; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).enterVariables(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ArrayStmtListener ) ((ArrayStmtListener)listener).exitVariables(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ArrayStmtVisitor ) return ((ArrayStmtVisitor<? extends T>)visitor).visitVariables(this);
			else return visitor.visitChildren(this);
		}
	}

	public final VariablesContext variables() throws RecognitionException {
		return variables(0);
	}

	private VariablesContext variables(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		VariablesContext _localctx = new VariablesContext(_ctx, _parentState);
		VariablesContext _prevctx = _localctx;
		int _startState = 34;
		enterRecursionRule(_localctx, 34, RULE_variables, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(330);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Identifier:
				{
				setState(326);
				match(Identifier);
				}
				break;
			case DATE:
				{
				setState(327);
				match(DATE);
				}
				break;
			case ALTER:
				{
				setState(328);
				match(ALTER);
				}
				break;
			case DROP:
				{
				setState(329);
				match(DROP);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(337);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,37,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new VariablesContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_variables);
					setState(332);
					if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
					setState(333);
					match(DOT);
					setState(334);
					variables(6);
					}
					} 
				}
				setState(339);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,37,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 10:
			return expression_sempred((ExpressionContext)_localctx, predIndex);
		case 11:
			return expressionList_sempred((ExpressionListContext)_localctx, predIndex);
		case 17:
			return variables_sempred((VariablesContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expression_sempred(ExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 13);
		case 1:
			return precpred(_ctx, 10);
		case 2:
			return precpred(_ctx, 9);
		case 3:
			return precpred(_ctx, 8);
		case 4:
			return precpred(_ctx, 7);
		case 5:
			return precpred(_ctx, 6);
		case 6:
			return precpred(_ctx, 5);
		case 7:
			return precpred(_ctx, 4);
		case 8:
			return precpred(_ctx, 2);
		case 9:
			return precpred(_ctx, 1);
		case 10:
			return precpred(_ctx, 16);
		case 11:
			return precpred(_ctx, 15);
		case 12:
			return precpred(_ctx, 14);
		case 13:
			return precpred(_ctx, 3);
		}
		return true;
	}
	private boolean expressionList_sempred(ExpressionListContext _localctx, int predIndex) {
		switch (predIndex) {
		case 14:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean variables_sempred(VariablesContext _localctx, int predIndex) {
		switch (predIndex) {
		case 15:
			return precpred(_ctx, 5);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\u00e8\u0157\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\3\2\7\2(\n\2\f\2\16\2+\13\2\3\2\3\2\3\3\3\3\3\3\3\3\3\3\3\3"+
		"\5\3\65\n\3\3\3\5\38\n\3\3\3\5\3;\n\3\3\3\5\3>\n\3\3\3\3\3\3\4\3\4\3\5"+
		"\3\5\3\5\3\5\7\5H\n\5\f\5\16\5K\13\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\7\5T"+
		"\n\5\f\5\16\5W\13\5\5\5Y\n\5\3\6\3\6\3\6\3\6\6\6_\n\6\r\6\16\6`\3\6\3"+
		"\6\3\6\5\6f\n\6\3\7\3\7\3\7\5\7k\n\7\3\7\7\7n\n\7\f\7\16\7q\13\7\3\7\3"+
		"\7\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\5\b\u0081\n\b\3\t\3"+
		"\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\5\t\u008d\n\t\3\t\5\t\u0090\n\t\3\t"+
		"\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\5\t\u009b\n\t\7\t\u009d\n\t\f\t\16\t"+
		"\u00a0\13\t\3\t\3\t\3\n\3\n\3\13\3\13\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f"+
		"\3\f\3\f\3\f\5\f\u00b3\n\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f"+
		"\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3"+
		"\f\3\f\3\f\3\f\3\f\5\f\u00d6\n\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3"+
		"\f\3\f\3\f\3\f\3\f\7\f\u00e6\n\f\f\f\16\f\u00e9\13\f\3\r\3\r\3\r\5\r\u00ee"+
		"\n\r\3\r\3\r\3\r\5\r\u00f3\n\r\7\r\u00f5\n\r\f\r\16\r\u00f8\13\r\3\r\3"+
		"\r\6\r\u00fc\n\r\r\r\16\r\u00fd\3\r\7\r\u0101\n\r\f\r\16\r\u0104\13\r"+
		"\3\16\3\16\3\16\3\16\3\16\3\16\3\16\5\16\u010d\n\16\3\16\3\16\3\16\7\16"+
		"\u0112\n\16\f\16\16\16\u0115\13\16\3\16\3\16\3\16\7\16\u011a\n\16\f\16"+
		"\16\16\u011d\13\16\3\16\3\16\3\16\3\16\3\16\5\16\u0124\n\16\3\17\3\17"+
		"\3\17\3\17\6\17\u012a\n\17\r\17\16\17\u012b\3\20\3\20\3\20\3\20\5\20\u0132"+
		"\n\20\3\20\3\20\3\20\5\20\u0137\n\20\7\20\u0139\n\20\f\20\16\20\u013c"+
		"\13\20\3\20\3\20\5\20\u0140\n\20\3\21\3\21\3\21\3\21\3\22\3\22\3\23\3"+
		"\23\3\23\3\23\3\23\5\23\u014d\n\23\3\23\3\23\3\23\7\23\u0152\n\23\f\23"+
		"\16\23\u0155\13\23\3\23\2\5\26\30$\24\2\4\6\b\n\f\16\20\22\24\26\30\32"+
		"\34\36 \"$\2\13\3\2\u00dc\u00de\4\2\6\6\16\16\4\2\4\4\17\20\3\2\21\22"+
		"\3\2\u00c3\u00c8\3\2\u00ca\u00cf\3\2\u00d1\u00d2\4\2\u00c9\u00c9\u00d0"+
		"\u00d0\4\2\u00d6\u00de\u00e0\u00e0\2\u0184\2)\3\2\2\2\4.\3\2\2\2\6A\3"+
		"\2\2\2\bX\3\2\2\2\ne\3\2\2\2\fg\3\2\2\2\16\u0080\3\2\2\2\20\u0082\3\2"+
		"\2\2\22\u00a3\3\2\2\2\24\u00a5\3\2\2\2\26\u00b2\3\2\2\2\30\u00ea\3\2\2"+
		"\2\32\u0123\3\2\2\2\34\u0129\3\2\2\2\36\u013f\3\2\2\2 \u0141\3\2\2\2\""+
		"\u0145\3\2\2\2$\u014c\3\2\2\2&(\5\4\3\2\'&\3\2\2\2(+\3\2\2\2)\'\3\2\2"+
		"\2)*\3\2\2\2*,\3\2\2\2+)\3\2\2\2,-\7\2\2\3-\3\3\2\2\2./\7u\2\2/\60\5\6"+
		"\4\2\60\61\7\u00e4\2\2\61\62\5\b\5\2\62\64\7\u00e5\2\2\63\65\7\u00c2\2"+
		"\2\64\63\3\2\2\2\64\65\3\2\2\2\65\67\3\2\2\2\668\7\u00dd\2\2\67\66\3\2"+
		"\2\2\678\3\2\2\28:\3\2\2\29;\5\n\6\2:9\3\2\2\2:;\3\2\2\2;=\3\2\2\2<>\5"+
		"\f\7\2=<\3\2\2\2=>\3\2\2\2>?\3\2\2\2?@\7\3\2\2@\5\3\2\2\2AB\7\u00df\2"+
		"\2B\7\3\2\2\2CY\7\4\2\2DI\7\u00dd\2\2EF\7\u00e3\2\2FH\7\u00dd\2\2GE\3"+
		"\2\2\2HK\3\2\2\2IG\3\2\2\2IJ\3\2\2\2JY\3\2\2\2KI\3\2\2\2LM\7\u00dd\2\2"+
		"MN\7\5\2\2NU\7\u00dd\2\2OP\7\u00e3\2\2PQ\7\u00dd\2\2QR\7\5\2\2RT\7\u00dd"+
		"\2\2SO\3\2\2\2TW\3\2\2\2US\3\2\2\2UV\3\2\2\2VY\3\2\2\2WU\3\2\2\2XC\3\2"+
		"\2\2XD\3\2\2\2XL\3\2\2\2Y\t\3\2\2\2Zf\7v\2\2[f\7w\2\2\\f\7x\2\2]_\7\u00df"+
		"\2\2^]\3\2\2\2_`\3\2\2\2`^\3\2\2\2`a\3\2\2\2af\3\2\2\2bc\7\u00df\2\2c"+
		"d\7\6\2\2df\7\u00df\2\2eZ\3\2\2\2e[\3\2\2\2e\\\3\2\2\2e^\3\2\2\2eb\3\2"+
		"\2\2f\13\3\2\2\2gh\7\7\2\2ho\5\16\b\2ik\7\u00e3\2\2ji\3\2\2\2jk\3\2\2"+
		"\2kl\3\2\2\2ln\5\16\b\2mj\3\2\2\2nq\3\2\2\2om\3\2\2\2op\3\2\2\2pr\3\2"+
		"\2\2qo\3\2\2\2rs\7\b\2\2s\r\3\2\2\2tu\7\u00dd\2\2uv\7\5\2\2v\u0081\7\u00dd"+
		"\2\2wx\5\22\n\2xy\7\4\2\2yz\5\f\7\2z\u0081\3\2\2\2{|\5\22\n\2|}\7\4\2"+
		"\2}~\5\24\13\2~\u0081\3\2\2\2\177\u0081\5\24\13\2\u0080t\3\2\2\2\u0080"+
		"w\3\2\2\2\u0080{\3\2\2\2\u0080\177\3\2\2\2\u0081\17\3\2\2\2\u0082\u008c"+
		"\7\7\2\2\u0083\u0084\5\22\n\2\u0084\u0085\7\4\2\2\u0085\u0086\5\f\7\2"+
		"\u0086\u008d\3\2\2\2\u0087\u0088\5\22\n\2\u0088\u0089\7\4\2\2\u0089\u008a"+
		"\5\24\13\2\u008a\u008d\3\2\2\2\u008b\u008d\5\24\13\2\u008c\u0083\3\2\2"+
		"\2\u008c\u0087\3\2\2\2\u008c\u008b\3\2\2\2\u008d\u009e\3\2\2\2\u008e\u0090"+
		"\7\u00e3\2\2\u008f\u008e\3\2\2\2\u008f\u0090\3\2\2\2\u0090\u009a\3\2\2"+
		"\2\u0091\u0092\5\22\n\2\u0092\u0093\7\4\2\2\u0093\u0094\5\f\7\2\u0094"+
		"\u009b\3\2\2\2\u0095\u0096\5\22\n\2\u0096\u0097\7\4\2\2\u0097\u0098\5"+
		"\24\13\2\u0098\u009b\3\2\2\2\u0099\u009b\5\24\13\2\u009a\u0091\3\2\2\2"+
		"\u009a\u0095\3\2\2\2\u009a\u0099\3\2\2\2\u009b\u009d\3\2\2\2\u009c\u008f"+
		"\3\2\2\2\u009d\u00a0\3\2\2\2\u009e\u009c\3\2\2\2\u009e\u009f\3\2\2\2\u009f"+
		"\u00a1\3\2\2\2\u00a0\u009e\3\2\2\2\u00a1\u00a2\7\b\2\2\u00a2\21\3\2\2"+
		"\2\u00a3\u00a4\7\u00dd\2\2\u00a4\23\3\2\2\2\u00a5\u00a6\t\2\2\2\u00a6"+
		"\25\3\2\2\2\u00a7\u00a8\b\f\1\2\u00a8\u00b3\5\"\22\2\u00a9\u00b3\7\u00df"+
		"\2\2\u00aa\u00ab\7\7\2\2\u00ab\u00ac\5\26\f\2\u00ac\u00ad\7\b\2\2\u00ad"+
		"\u00b3\3\2\2\2\u00ae\u00af\t\3\2\2\u00af\u00b3\5\26\f\16\u00b0\u00b1\7"+
		"\u00d3\2\2\u00b1\u00b3\5\26\f\r\u00b2\u00a7\3\2\2\2\u00b2\u00a9\3\2\2"+
		"\2\u00b2\u00aa\3\2\2\2\u00b2\u00ae\3\2\2\2\u00b2\u00b0\3\2\2\2\u00b3\u00e7"+
		"\3\2\2\2\u00b4\u00b5\f\17\2\2\u00b5\u00b6\7\r\2\2\u00b6\u00e6\5\26\f\17"+
		"\u00b7\u00b8\f\f\2\2\u00b8\u00b9\7\u00d4\2\2\u00b9\u00e6\5\26\f\r\u00ba"+
		"\u00bb\f\13\2\2\u00bb\u00bc\7\u00d5\2\2\u00bc\u00e6\5\26\f\f\u00bd\u00be"+
		"\f\n\2\2\u00be\u00bf\t\4\2\2\u00bf\u00e6\5\26\f\13\u00c0\u00c1\f\t\2\2"+
		"\u00c1\u00c2\t\3\2\2\u00c2\u00e6\5\26\f\n\u00c3\u00c4\f\b\2\2\u00c4\u00c5"+
		"\t\5\2\2\u00c5\u00e6\5\26\f\t\u00c6\u00c7\f\7\2\2\u00c7\u00c8\t\6\2\2"+
		"\u00c8\u00e6\5\26\f\b\u00c9\u00ca\f\6\2\2\u00ca\u00cb\t\7\2\2\u00cb\u00e6"+
		"\5\26\f\7\u00cc\u00cd\f\4\2\2\u00cd\u00ce\t\b\2\2\u00ce\u00e6\5\26\f\5"+
		"\u00cf\u00d0\f\3\2\2\u00d0\u00d1\7\u00e2\2\2\u00d1\u00e6\5\26\f\3\u00d2"+
		"\u00d3\f\22\2\2\u00d3\u00d5\7\7\2\2\u00d4\u00d6\5\30\r\2\u00d5\u00d4\3"+
		"\2\2\2\u00d5\u00d6\3\2\2\2\u00d6\u00d7\3\2\2\2\u00d7\u00e6\7\b\2\2\u00d8"+
		"\u00d9\f\21\2\2\u00d9\u00da\7\t\2\2\u00da\u00db\5\26\f\2\u00db\u00dc\7"+
		"\n\2\2\u00dc\u00e6\3\2\2\2\u00dd\u00de\f\20\2\2\u00de\u00df\7\13\2\2\u00df"+
		"\u00e0\5\26\f\2\u00e0\u00e1\7\f\2\2\u00e1\u00e6\3\2\2\2\u00e2\u00e3\f"+
		"\5\2\2\u00e3\u00e4\t\t\2\2\u00e4\u00e6\5\36\20\2\u00e5\u00b4\3\2\2\2\u00e5"+
		"\u00b7\3\2\2\2\u00e5\u00ba\3\2\2\2\u00e5\u00bd\3\2\2\2\u00e5\u00c0\3\2"+
		"\2\2\u00e5\u00c3\3\2\2\2\u00e5\u00c6\3\2\2\2\u00e5\u00c9\3\2\2\2\u00e5"+
		"\u00cc\3\2\2\2\u00e5\u00cf\3\2\2\2\u00e5\u00d2\3\2\2\2\u00e5\u00d8\3\2"+
		"\2\2\u00e5\u00dd\3\2\2\2\u00e5\u00e2\3\2\2\2\u00e6\u00e9\3\2\2\2\u00e7"+
		"\u00e5\3\2\2\2\u00e7\u00e8\3\2\2\2\u00e8\27\3\2\2\2\u00e9\u00e7\3\2\2"+
		"\2\u00ea\u00ed\b\r\1\2\u00eb\u00ee\5\26\f\2\u00ec\u00ee\5\32\16\2\u00ed"+
		"\u00eb\3\2\2\2\u00ed\u00ec\3\2\2\2\u00ee\u00f6\3\2\2\2\u00ef\u00f2\7\u00e3"+
		"\2\2\u00f0\u00f3\5\26\f\2\u00f1\u00f3\5\32\16\2\u00f2\u00f0\3\2\2\2\u00f2"+
		"\u00f1\3\2\2\2\u00f3\u00f5\3\2\2\2\u00f4\u00ef\3\2\2\2\u00f5\u00f8\3\2"+
		"\2\2\u00f6\u00f4\3\2\2\2\u00f6\u00f7\3\2\2\2\u00f7\u0102\3\2\2\2\u00f8"+
		"\u00f6\3\2\2\2\u00f9\u00fb\f\3\2\2\u00fa\u00fc\7\u00e3\2\2\u00fb\u00fa"+
		"\3\2\2\2\u00fc\u00fd\3\2\2\2\u00fd\u00fb\3\2\2\2\u00fd\u00fe\3\2\2\2\u00fe"+
		"\u00ff\3\2\2\2\u00ff\u0101\5\30\r\4\u0100\u00f9\3\2\2\2\u0101\u0104\3"+
		"\2\2\2\u0102\u0100\3\2\2\2\u0102\u0103\3\2\2\2\u0103\31\3\2\2\2\u0104"+
		"\u0102\3\2\2\2\u0105\u0106\7\23\2\2\u0106\u0107\7\u00df\2\2\u0107\u0108"+
		"\7\6\2\2\u0108\u0109\7\u00df\2\2\u0109\u0113\3\2\2\2\u010a\u010b\7\u00e3"+
		"\2\2\u010b\u010d\7\23\2\2\u010c\u010a\3\2\2\2\u010c\u010d\3\2\2\2\u010d"+
		"\u010e\3\2\2\2\u010e\u010f\7\u00df\2\2\u010f\u0110\7\6\2\2\u0110\u0112"+
		"\7\u00df\2\2\u0111\u010c\3\2\2\2\u0112\u0115\3\2\2\2\u0113\u0111\3\2\2"+
		"\2\u0113\u0114\3\2\2\2\u0114\u0124\3\2\2\2\u0115\u0113\3\2\2\2\u0116\u0117"+
		"\7\23\2\2\u0117\u011b\7\u00df\2\2\u0118\u011a\7\u00df\2\2\u0119\u0118"+
		"\3\2\2\2\u011a\u011d\3\2\2\2\u011b\u0119\3\2\2\2\u011b\u011c\3\2\2\2\u011c"+
		"\u0124\3\2\2\2\u011d\u011b\3\2\2\2\u011e\u011f\7\23\2\2\u011f\u0120\7"+
		"\u00df\2\2\u0120\u0121\7\13\2\2\u0121\u0122\7\4\2\2\u0122\u0124\7\f\2"+
		"\2\u0123\u0105\3\2\2\2\u0123\u0116\3\2\2\2\u0123\u011e\3\2\2\2\u0124\33"+
		"\3\2\2\2\u0125\u012a\7\u00df\2\2\u0126\u0127\7\u00df\2\2\u0127\u0128\7"+
		"\6\2\2\u0128\u012a\7\u00df\2\2\u0129\u0125\3\2\2\2\u0129\u0126\3\2\2\2"+
		"\u012a\u012b\3\2\2\2\u012b\u0129\3\2\2\2\u012b\u012c\3\2\2\2\u012c\35"+
		"\3\2\2\2\u012d\u0140\7\u00df\2\2\u012e\u0131\7\7\2\2\u012f\u0132\5\"\22"+
		"\2\u0130\u0132\5 \21\2\u0131\u012f\3\2\2\2\u0131\u0130\3\2\2\2\u0132\u013a"+
		"\3\2\2\2\u0133\u0136\7\u00e3\2\2\u0134\u0137\5\"\22\2\u0135\u0137\5 \21"+
		"\2\u0136\u0134\3\2\2\2\u0136\u0135\3\2\2\2\u0137\u0139\3\2\2\2\u0138\u0133"+
		"\3\2\2\2\u0139\u013c\3\2\2\2\u013a\u0138\3\2\2\2\u013a\u013b\3\2\2\2\u013b"+
		"\u013d\3\2\2\2\u013c\u013a\3\2\2\2\u013d\u013e\7\b\2\2\u013e\u0140\3\2"+
		"\2\2\u013f\u012d\3\2\2\2\u013f\u012e\3\2\2\2\u0140\37\3\2\2\2\u0141\u0142"+
		"\7\u00dd\2\2\u0142\u0143\7\5\2\2\u0143\u0144\7\u00dd\2\2\u0144!\3\2\2"+
		"\2\u0145\u0146\t\n\2\2\u0146#\3\2\2\2\u0147\u0148\b\23\1\2\u0148\u014d"+
		"\7\u00df\2\2\u0149\u014d\7\u00a6\2\2\u014a\u014d\7\u008e\2\2\u014b\u014d"+
		"\7\u00ab\2\2\u014c\u0147\3\2\2\2\u014c\u0149\3\2\2\2\u014c\u014a\3\2\2"+
		"\2\u014c\u014b\3\2\2\2\u014d\u0153\3\2\2\2\u014e\u014f\f\7\2\2\u014f\u0150"+
		"\7\u00e0\2\2\u0150\u0152\5$\23\b\u0151\u014e\3\2\2\2\u0152\u0155\3\2\2"+
		"\2\u0153\u0151\3\2\2\2\u0153\u0154\3\2\2\2\u0154%\3\2\2\2\u0155\u0153"+
		"\3\2\2\2()\64\67:=IUX`ejo\u0080\u008c\u008f\u009a\u009e\u00b2\u00d5\u00e5"+
		"\u00e7\u00ed\u00f2\u00f6\u00fd\u0102\u010c\u0113\u011b\u0123\u0129\u012b"+
		"\u0131\u0136\u013a\u013f\u014c\u0153";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}