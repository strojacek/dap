// Generated from MeansProc.g4 by ANTLR 4.8
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class MeansProcParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, T__16=17, 
		SK_MIN=18, SK_MAX=19, SK_MEAN=20, SK_N=21, SK_SUM=22, SK_VAR=23, SUMSIZE=24, 
		NOTRAP=25, ABEND=26, END=27, LENGTH=28, QKUPCASE=29, SYSEVALF=30, ABORT=31, 
		EVAL=32, LET=33, QSCAN=34, SYSEXEC=35, ACT=36, FILE=37, LIST=38, QSUBSTR=39, 
		SYSFUNC=40, ACTIVATE=41, GLOBAL=42, LISTM=43, QSYSFUNC=44, SYSGET=45, 
		BQUOTE=46, GO=47, LOCAL=48, QUOTE=49, SYSRPUT=50, BY=51, GOTO=52, MACRO=53, 
		QUPCASE=54, THEN=55, CLEAR=56, IF=57, MEND=58, RESOLVE=59, TO=60, CLOSE=61, 
		INC=62, PAUSE=63, RETURN=64, TSO=65, CMS=66, INCLUDE=67, NRSTR=68, RUN=69, 
		UNQUOTE=70, COMANDR=71, INDEX=72, ON=73, SAVE=74, UNSTR=75, COPY=76, INFILE=77, 
		OPEN=78, SCAN=79, UNTIL=80, DEACT=81, INPUT=82, PUT=83, STOP=84, UPCASE=85, 
		DEL=86, KCMPRES=87, NRBQUOTE=88, STR=89, WHILE=90, DELETE=91, KINDEX=92, 
		NRQUOTE=93, SYSCALL=94, WINDOW=95, DISPLAY=96, KLEFT=97, METASYM=98, SUBSTR=99, 
		DMIDSPLY=100, KLENGTH=101, QKCMPRES=102, SUPERQ=103, DMISPLIT=104, KSCAN=105, 
		QKLEFT=106, SYMDEL=107, DO=108, KSUBSTR=109, QKSCAN=110, SYMEXIST=111, 
		EDIT=112, KTRIM=113, QKSUBSTR=114, SYMGLOBL=115, ELSE=116, KUPCASE=117, 
		QKTRIM=118, SYMLOCAL=119, Tk_NULL=120, CANCEL=121, NOLIST=122, ARRAY=123, 
		ARRAY_NUMERIC_ELEMENTS=124, ARRAY_CHARACTER_ELEMENTS=125, ARRAY_ALL_ELEMENTS=126, 
		GROUPFORMAT=127, NOTSORTED=128, DESCENDING=129, CALL=130, DEBUG=131, NESTING=132, 
		STACK=133, READ=134, PW=135, SOURCE=136, VIEW=137, PGM=138, ENCRYPT=139, 
		NOSAVE=140, DATALINES=141, CARDS=142, LINES=143, DATALINES4=144, CARDS4=145, 
		LINES4=146, END_DATALINES4=147, ALTER=148, DISK=149, DUMMY=150, GTERM=151, 
		PIPE=152, PLOTTER=153, PRINTER=154, TAPE=155, TEMP=156, TERMINAL=157, 
		UPRINTER=158, DSD=159, EXPANDTABS=160, NOEXPANDTABS=161, FLOWOVER=162, 
		MISSOVER=163, PAD=164, NOPAD=165, SCANOVER=166, SHAREBUFFERS=167, STOPOVER=168, 
		TRUNCOVER=169, V_INFILE_=170, INPUT_ODS=171, DATE=172, DATETIME=173, DDMMYY=174, 
		INFORMAT_COMMA=175, INFORMAT_CHAR=176, DROP=177, PROC=178, ANOVA=179, 
		MEANS=180, REG=181, CORR=182, SGPLOT=183, PRINT=184, DATA=185, GLM=186, 
		FREQ=187, SQL=188, UNIVARIATE=189, NPAR1WAY=190, IMPORT=191, SORT=192, 
		DATASETS=193, TABULATE=194, RANK=195, CHART=196, LOGISTIC=197, SURVEYSELECT=198, 
		Informat=199, DOLLAR=200, EQ=201, NE=202, GT=203, LT=204, GE=205, LE=206, 
		IN=207, EQC=208, NEC=209, GTC=210, LTC=211, GEC=212, LEC=213, INColon=214, 
		AND=215, OR=216, NOT=217, MIN=218, MAX=219, DateLiteral=220, TimeLiteral=221, 
		DateTimeLiteral=222, BitLiteral=223, NameLiteral=224, HexLiteral=225, 
		STRINGLITERAL=226, INT=227, FloatingPointLiteral=228, Identifier=229, 
		DOT=230, AT=231, EQUAL=232, COMMA=233, LBracket=234, RBracket=235, WS=236, 
		COMMENT=237, LINE_COMMENT=238;
	public static final int
		RULE_means_main = 0, RULE_means_proc = 1, RULE_statistic_keyword = 2, 
		RULE_spaced_identifiers = 3, RULE_var_stmt = 4, RULE_expression = 5, RULE_expressionList = 6, 
		RULE_of_var_list = 7, RULE_identifiers_list = 8, RULE_in_var_list = 9, 
		RULE_colonInts = 10, RULE_literal = 11, RULE_variables = 12;
	private static String[] makeRuleNames() {
		return new String[] {
			"means_main", "means_proc", "statistic_keyword", "spaced_identifiers", 
			"var_stmt", "expression", "expressionList", "of_var_list", "identifiers_list", 
			"in_var_list", "colonInts", "literal", "variables"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'-'", "';'", "'('", "')'", "'{'", "'}'", "'['", "']'", "'**'", 
			"'+'", "'*'", "'/'", "'%'", "'||'", "'!!'", "'of'", "':'", "'MIN'", "'MAX'", 
			"'MEAN'", "'N'", "'SUM'", "'VAR'", "'SUMSIZE'", "'NOTRAP'", null, null, 
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
			null, null, null, null, null, null, "SK_MIN", "SK_MAX", "SK_MEAN", "SK_N", 
			"SK_SUM", "SK_VAR", "SUMSIZE", "NOTRAP", "ABEND", "END", "LENGTH", "QKUPCASE", 
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
	public String getGrammarFileName() { return "MeansProc.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public MeansProcParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class Means_mainContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(MeansProcParser.EOF, 0); }
		public List<Means_procContext> means_proc() {
			return getRuleContexts(Means_procContext.class);
		}
		public Means_procContext means_proc(int i) {
			return getRuleContext(Means_procContext.class,i);
		}
		public Means_mainContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_means_main; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MeansProcListener ) ((MeansProcListener)listener).enterMeans_main(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MeansProcListener ) ((MeansProcListener)listener).exitMeans_main(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MeansProcVisitor ) return ((MeansProcVisitor<? extends T>)visitor).visitMeans_main(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Means_mainContext means_main() throws RecognitionException {
		Means_mainContext _localctx = new Means_mainContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_means_main);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(29);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__1) | (1L << SK_MIN) | (1L << SK_MAX) | (1L << SK_MEAN) | (1L << SK_N) | (1L << SK_SUM) | (1L << SK_VAR) | (1L << SUMSIZE) | (1L << NOTRAP))) != 0) || _la==DROP || _la==Identifier) {
				{
				{
				setState(26);
				means_proc();
				}
				}
				setState(31);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(32);
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

	public static class Means_procContext extends ParserRuleContext {
		public TerminalNode DROP() { return getToken(MeansProcParser.DROP, 0); }
		public List<VariablesContext> variables() {
			return getRuleContexts(VariablesContext.class);
		}
		public VariablesContext variables(int i) {
			return getRuleContext(VariablesContext.class,i);
		}
		public TerminalNode NOTRAP() { return getToken(MeansProcParser.NOTRAP, 0); }
		public TerminalNode SUMSIZE() { return getToken(MeansProcParser.SUMSIZE, 0); }
		public TerminalNode EQUAL() { return getToken(MeansProcParser.EQUAL, 0); }
		public List<Statistic_keywordContext> statistic_keyword() {
			return getRuleContexts(Statistic_keywordContext.class);
		}
		public Statistic_keywordContext statistic_keyword(int i) {
			return getRuleContext(Statistic_keywordContext.class,i);
		}
		public Var_stmtContext var_stmt() {
			return getRuleContext(Var_stmtContext.class,0);
		}
		public Means_procContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_means_proc; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MeansProcListener ) ((MeansProcListener)listener).enterMeans_proc(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MeansProcListener ) ((MeansProcListener)listener).exitMeans_proc(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MeansProcVisitor ) return ((MeansProcVisitor<? extends T>)visitor).visitMeans_proc(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Means_procContext means_proc() throws RecognitionException {
		Means_procContext _localctx = new Means_procContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_means_proc);
		int _la;
		try {
			setState(57);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case DROP:
				enterOuterAlt(_localctx, 1);
				{
				setState(34);
				match(DROP);
				setState(40); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					setState(40);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
					case 1:
						{
						setState(35);
						variables(0);
						}
						break;
					case 2:
						{
						setState(36);
						variables(0);
						setState(37);
						match(T__0);
						setState(38);
						variables(0);
						}
						break;
					}
					}
					setState(42); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( ((((_la - 148)) & ~0x3f) == 0 && ((1L << (_la - 148)) & ((1L << (ALTER - 148)) | (1L << (DATE - 148)) | (1L << (DROP - 148)))) != 0) || _la==Identifier );
				setState(44);
				match(T__1);
				}
				break;
			case NOTRAP:
				enterOuterAlt(_localctx, 2);
				{
				setState(46);
				match(NOTRAP);
				}
				break;
			case SUMSIZE:
				enterOuterAlt(_localctx, 3);
				{
				setState(47);
				match(SUMSIZE);
				setState(48);
				match(EQUAL);
				}
				break;
			case T__1:
			case SK_MIN:
			case SK_MAX:
			case SK_MEAN:
			case SK_N:
			case SK_SUM:
			case SK_VAR:
				enterOuterAlt(_localctx, 4);
				{
				setState(52);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << SK_MIN) | (1L << SK_MAX) | (1L << SK_MEAN) | (1L << SK_N) | (1L << SK_SUM) | (1L << SK_VAR))) != 0)) {
					{
					{
					setState(49);
					statistic_keyword();
					}
					}
					setState(54);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(55);
				match(T__1);
				}
				break;
			case Identifier:
				enterOuterAlt(_localctx, 5);
				{
				setState(56);
				var_stmt();
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

	public static class Statistic_keywordContext extends ParserRuleContext {
		public TerminalNode SK_MIN() { return getToken(MeansProcParser.SK_MIN, 0); }
		public TerminalNode SK_MAX() { return getToken(MeansProcParser.SK_MAX, 0); }
		public TerminalNode SK_MEAN() { return getToken(MeansProcParser.SK_MEAN, 0); }
		public TerminalNode SK_N() { return getToken(MeansProcParser.SK_N, 0); }
		public TerminalNode SK_SUM() { return getToken(MeansProcParser.SK_SUM, 0); }
		public TerminalNode SK_VAR() { return getToken(MeansProcParser.SK_VAR, 0); }
		public Statistic_keywordContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statistic_keyword; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MeansProcListener ) ((MeansProcListener)listener).enterStatistic_keyword(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MeansProcListener ) ((MeansProcListener)listener).exitStatistic_keyword(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MeansProcVisitor ) return ((MeansProcVisitor<? extends T>)visitor).visitStatistic_keyword(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Statistic_keywordContext statistic_keyword() throws RecognitionException {
		Statistic_keywordContext _localctx = new Statistic_keywordContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_statistic_keyword);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(59);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << SK_MIN) | (1L << SK_MAX) | (1L << SK_MEAN) | (1L << SK_N) | (1L << SK_SUM) | (1L << SK_VAR))) != 0)) ) {
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

	public static class Spaced_identifiersContext extends ParserRuleContext {
		public List<TerminalNode> Identifier() { return getTokens(MeansProcParser.Identifier); }
		public TerminalNode Identifier(int i) {
			return getToken(MeansProcParser.Identifier, i);
		}
		public Spaced_identifiersContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_spaced_identifiers; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MeansProcListener ) ((MeansProcListener)listener).enterSpaced_identifiers(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MeansProcListener ) ((MeansProcListener)listener).exitSpaced_identifiers(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MeansProcVisitor ) return ((MeansProcVisitor<? extends T>)visitor).visitSpaced_identifiers(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Spaced_identifiersContext spaced_identifiers() throws RecognitionException {
		Spaced_identifiersContext _localctx = new Spaced_identifiersContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_spaced_identifiers);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(61);
			match(Identifier);
			setState(65);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==Identifier) {
				{
				{
				setState(62);
				match(Identifier);
				}
				}
				setState(67);
				_errHandler.sync(this);
				_la = _input.LA(1);
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

	public static class Var_stmtContext extends ParserRuleContext {
		public Spaced_identifiersContext spaced_identifiers() {
			return getRuleContext(Spaced_identifiersContext.class,0);
		}
		public Var_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_var_stmt; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MeansProcListener ) ((MeansProcListener)listener).enterVar_stmt(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MeansProcListener ) ((MeansProcListener)listener).exitVar_stmt(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MeansProcVisitor ) return ((MeansProcVisitor<? extends T>)visitor).visitVar_stmt(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Var_stmtContext var_stmt() throws RecognitionException {
		Var_stmtContext _localctx = new Var_stmtContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_var_stmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(68);
			spaced_identifiers();
			setState(69);
			match(T__1);
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
		public TerminalNode Identifier() { return getToken(MeansProcParser.Identifier, 0); }
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode NOT() { return getToken(MeansProcParser.NOT, 0); }
		public TerminalNode MIN() { return getToken(MeansProcParser.MIN, 0); }
		public TerminalNode MAX() { return getToken(MeansProcParser.MAX, 0); }
		public TerminalNode EQ() { return getToken(MeansProcParser.EQ, 0); }
		public TerminalNode NE() { return getToken(MeansProcParser.NE, 0); }
		public TerminalNode GT() { return getToken(MeansProcParser.GT, 0); }
		public TerminalNode LT() { return getToken(MeansProcParser.LT, 0); }
		public TerminalNode GE() { return getToken(MeansProcParser.GE, 0); }
		public TerminalNode LE() { return getToken(MeansProcParser.LE, 0); }
		public TerminalNode EQC() { return getToken(MeansProcParser.EQC, 0); }
		public TerminalNode NEC() { return getToken(MeansProcParser.NEC, 0); }
		public TerminalNode GTC() { return getToken(MeansProcParser.GTC, 0); }
		public TerminalNode LTC() { return getToken(MeansProcParser.LTC, 0); }
		public TerminalNode GEC() { return getToken(MeansProcParser.GEC, 0); }
		public TerminalNode LEC() { return getToken(MeansProcParser.LEC, 0); }
		public TerminalNode AND() { return getToken(MeansProcParser.AND, 0); }
		public TerminalNode OR() { return getToken(MeansProcParser.OR, 0); }
		public TerminalNode EQUAL() { return getToken(MeansProcParser.EQUAL, 0); }
		public ExpressionListContext expressionList() {
			return getRuleContext(ExpressionListContext.class,0);
		}
		public In_var_listContext in_var_list() {
			return getRuleContext(In_var_listContext.class,0);
		}
		public TerminalNode IN() { return getToken(MeansProcParser.IN, 0); }
		public TerminalNode INColon() { return getToken(MeansProcParser.INColon, 0); }
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MeansProcListener ) ((MeansProcListener)listener).enterExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MeansProcListener ) ((MeansProcListener)listener).exitExpression(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MeansProcVisitor ) return ((MeansProcVisitor<? extends T>)visitor).visitExpression(this);
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
		int _startState = 10;
		enterRecursionRule(_localctx, 10, RULE_expression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(82);
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
				setState(72);
				literal();
				}
				break;
			case Identifier:
				{
				setState(73);
				match(Identifier);
				}
				break;
			case T__2:
				{
				setState(74);
				match(T__2);
				setState(75);
				expression(0);
				setState(76);
				match(T__3);
				}
				break;
			case T__0:
			case T__9:
				{
				setState(78);
				_la = _input.LA(1);
				if ( !(_la==T__0 || _la==T__9) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(79);
				expression(12);
				}
				break;
			case NOT:
				{
				setState(80);
				match(NOT);
				setState(81);
				expression(11);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(135);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,9,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(133);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
					case 1:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(84);
						if (!(precpred(_ctx, 13))) throw new FailedPredicateException(this, "precpred(_ctx, 13)");
						setState(85);
						match(T__8);
						setState(86);
						expression(13);
						}
						break;
					case 2:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(87);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(88);
						match(MIN);
						setState(89);
						expression(11);
						}
						break;
					case 3:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(90);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(91);
						match(MAX);
						setState(92);
						expression(10);
						}
						break;
					case 4:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(93);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(94);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__10) | (1L << T__11) | (1L << T__12))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(95);
						expression(9);
						}
						break;
					case 5:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(96);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(97);
						_la = _input.LA(1);
						if ( !(_la==T__0 || _la==T__9) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(98);
						expression(8);
						}
						break;
					case 6:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(99);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(100);
						_la = _input.LA(1);
						if ( !(_la==T__13 || _la==T__14) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(101);
						expression(7);
						}
						break;
					case 7:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(102);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(103);
						_la = _input.LA(1);
						if ( !(((((_la - 201)) & ~0x3f) == 0 && ((1L << (_la - 201)) & ((1L << (EQ - 201)) | (1L << (NE - 201)) | (1L << (GT - 201)) | (1L << (LT - 201)) | (1L << (GE - 201)) | (1L << (LE - 201)))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(104);
						expression(6);
						}
						break;
					case 8:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(105);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(106);
						_la = _input.LA(1);
						if ( !(((((_la - 208)) & ~0x3f) == 0 && ((1L << (_la - 208)) & ((1L << (EQC - 208)) | (1L << (NEC - 208)) | (1L << (GTC - 208)) | (1L << (LTC - 208)) | (1L << (GEC - 208)) | (1L << (LEC - 208)))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(107);
						expression(5);
						}
						break;
					case 9:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(108);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(109);
						_la = _input.LA(1);
						if ( !(_la==AND || _la==OR) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(110);
						expression(3);
						}
						break;
					case 10:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(111);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(112);
						match(EQUAL);
						setState(113);
						expression(1);
						}
						break;
					case 11:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(114);
						if (!(precpred(_ctx, 16))) throw new FailedPredicateException(this, "precpred(_ctx, 16)");
						setState(115);
						match(T__2);
						setState(117);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__2) | (1L << T__9) | (1L << T__15))) != 0) || ((((_la - 217)) & ~0x3f) == 0 && ((1L << (_la - 217)) & ((1L << (NOT - 217)) | (1L << (DateLiteral - 217)) | (1L << (TimeLiteral - 217)) | (1L << (DateTimeLiteral - 217)) | (1L << (BitLiteral - 217)) | (1L << (NameLiteral - 217)) | (1L << (HexLiteral - 217)) | (1L << (STRINGLITERAL - 217)) | (1L << (INT - 217)) | (1L << (FloatingPointLiteral - 217)) | (1L << (Identifier - 217)) | (1L << (DOT - 217)))) != 0)) {
							{
							setState(116);
							expressionList(0);
							}
						}

						setState(119);
						match(T__3);
						}
						break;
					case 12:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(120);
						if (!(precpred(_ctx, 15))) throw new FailedPredicateException(this, "precpred(_ctx, 15)");
						setState(121);
						match(T__4);
						setState(122);
						expression(0);
						setState(123);
						match(T__5);
						}
						break;
					case 13:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(125);
						if (!(precpred(_ctx, 14))) throw new FailedPredicateException(this, "precpred(_ctx, 14)");
						setState(126);
						match(T__6);
						setState(127);
						expression(0);
						setState(128);
						match(T__7);
						}
						break;
					case 14:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(130);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(131);
						_la = _input.LA(1);
						if ( !(_la==IN || _la==INColon) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(132);
						in_var_list();
						}
						break;
					}
					} 
				}
				setState(137);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,9,_ctx);
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
		public List<TerminalNode> COMMA() { return getTokens(MeansProcParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(MeansProcParser.COMMA, i);
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
			if ( listener instanceof MeansProcListener ) ((MeansProcListener)listener).enterExpressionList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MeansProcListener ) ((MeansProcListener)listener).exitExpressionList(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MeansProcVisitor ) return ((MeansProcVisitor<? extends T>)visitor).visitExpressionList(this);
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
		int _startState = 12;
		enterRecursionRule(_localctx, 12, RULE_expressionList, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(141);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__0:
			case T__2:
			case T__9:
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
				setState(139);
				expression(0);
				}
				break;
			case T__15:
				{
				setState(140);
				of_var_list();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(150);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(143);
					match(COMMA);
					setState(146);
					_errHandler.sync(this);
					switch (_input.LA(1)) {
					case T__0:
					case T__2:
					case T__9:
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
						setState(144);
						expression(0);
						}
						break;
					case T__15:
						{
						setState(145);
						of_var_list();
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					}
					} 
				}
				setState(152);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			}
			}
			_ctx.stop = _input.LT(-1);
			setState(162);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ExpressionListContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_expressionList);
					setState(153);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(155); 
					_errHandler.sync(this);
					_la = _input.LA(1);
					do {
						{
						{
						setState(154);
						match(COMMA);
						}
						}
						setState(157); 
						_errHandler.sync(this);
						_la = _input.LA(1);
					} while ( _la==COMMA );
					setState(159);
					expressionList(2);
					}
					} 
				}
				setState(164);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
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
		public List<TerminalNode> Identifier() { return getTokens(MeansProcParser.Identifier); }
		public TerminalNode Identifier(int i) {
			return getToken(MeansProcParser.Identifier, i);
		}
		public List<TerminalNode> COMMA() { return getTokens(MeansProcParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(MeansProcParser.COMMA, i);
		}
		public Of_var_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_of_var_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MeansProcListener ) ((MeansProcListener)listener).enterOf_var_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MeansProcListener ) ((MeansProcListener)listener).exitOf_var_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MeansProcVisitor ) return ((MeansProcVisitor<? extends T>)visitor).visitOf_var_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Of_var_listContext of_var_list() throws RecognitionException {
		Of_var_listContext _localctx = new Of_var_listContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_of_var_list);
		int _la;
		try {
			int _alt;
			setState(195);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(165);
				match(T__15);
				{
				setState(166);
				match(Identifier);
				setState(167);
				match(T__0);
				setState(168);
				match(Identifier);
				}
				setState(179);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,16,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(172);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if (_la==COMMA) {
							{
							setState(170);
							match(COMMA);
							setState(171);
							match(T__15);
							}
						}

						{
						setState(174);
						match(Identifier);
						setState(175);
						match(T__0);
						setState(176);
						match(Identifier);
						}
						}
						} 
					}
					setState(181);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,16,_ctx);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(182);
				match(T__15);
				setState(183);
				match(Identifier);
				setState(187);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,17,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(184);
						match(Identifier);
						}
						} 
					}
					setState(189);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,17,_ctx);
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(190);
				match(T__15);
				setState(191);
				match(Identifier);
				setState(192);
				match(T__6);
				setState(193);
				match(T__10);
				setState(194);
				match(T__7);
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
		public List<TerminalNode> Identifier() { return getTokens(MeansProcParser.Identifier); }
		public TerminalNode Identifier(int i) {
			return getToken(MeansProcParser.Identifier, i);
		}
		public Identifiers_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_identifiers_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MeansProcListener ) ((MeansProcListener)listener).enterIdentifiers_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MeansProcListener ) ((MeansProcListener)listener).exitIdentifiers_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MeansProcVisitor ) return ((MeansProcVisitor<? extends T>)visitor).visitIdentifiers_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Identifiers_listContext identifiers_list() throws RecognitionException {
		Identifiers_listContext _localctx = new Identifiers_listContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_identifiers_list);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(201); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				setState(201);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,19,_ctx) ) {
				case 1:
					{
					setState(197);
					match(Identifier);
					}
					break;
				case 2:
					{
					setState(198);
					match(Identifier);
					setState(199);
					match(T__0);
					setState(200);
					match(Identifier);
					}
					break;
				}
				}
				setState(203); 
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
		public TerminalNode Identifier() { return getToken(MeansProcParser.Identifier, 0); }
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
		public List<TerminalNode> COMMA() { return getTokens(MeansProcParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(MeansProcParser.COMMA, i);
		}
		public In_var_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_in_var_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MeansProcListener ) ((MeansProcListener)listener).enterIn_var_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MeansProcListener ) ((MeansProcListener)listener).exitIn_var_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MeansProcVisitor ) return ((MeansProcVisitor<? extends T>)visitor).visitIn_var_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final In_var_listContext in_var_list() throws RecognitionException {
		In_var_listContext _localctx = new In_var_listContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_in_var_list);
		int _la;
		try {
			setState(223);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Identifier:
				enterOuterAlt(_localctx, 1);
				{
				setState(205);
				match(Identifier);
				}
				break;
			case T__2:
				enterOuterAlt(_localctx, 2);
				{
				setState(206);
				match(T__2);
				setState(209);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,21,_ctx) ) {
				case 1:
					{
					setState(207);
					literal();
					}
					break;
				case 2:
					{
					setState(208);
					colonInts();
					}
					break;
				}
				setState(218);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMMA) {
					{
					{
					setState(211);
					match(COMMA);
					setState(214);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,22,_ctx) ) {
					case 1:
						{
						setState(212);
						literal();
						}
						break;
					case 2:
						{
						setState(213);
						colonInts();
						}
						break;
					}
					}
					}
					setState(220);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(221);
				match(T__3);
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
		public List<TerminalNode> INT() { return getTokens(MeansProcParser.INT); }
		public TerminalNode INT(int i) {
			return getToken(MeansProcParser.INT, i);
		}
		public ColonIntsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_colonInts; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MeansProcListener ) ((MeansProcListener)listener).enterColonInts(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MeansProcListener ) ((MeansProcListener)listener).exitColonInts(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MeansProcVisitor ) return ((MeansProcVisitor<? extends T>)visitor).visitColonInts(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ColonIntsContext colonInts() throws RecognitionException {
		ColonIntsContext _localctx = new ColonIntsContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_colonInts);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(225);
			match(INT);
			setState(226);
			match(T__16);
			setState(227);
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
		public TerminalNode INT() { return getToken(MeansProcParser.INT, 0); }
		public TerminalNode FloatingPointLiteral() { return getToken(MeansProcParser.FloatingPointLiteral, 0); }
		public TerminalNode STRINGLITERAL() { return getToken(MeansProcParser.STRINGLITERAL, 0); }
		public TerminalNode DateLiteral() { return getToken(MeansProcParser.DateLiteral, 0); }
		public TerminalNode TimeLiteral() { return getToken(MeansProcParser.TimeLiteral, 0); }
		public TerminalNode DateTimeLiteral() { return getToken(MeansProcParser.DateTimeLiteral, 0); }
		public TerminalNode BitLiteral() { return getToken(MeansProcParser.BitLiteral, 0); }
		public TerminalNode NameLiteral() { return getToken(MeansProcParser.NameLiteral, 0); }
		public TerminalNode HexLiteral() { return getToken(MeansProcParser.HexLiteral, 0); }
		public TerminalNode DOT() { return getToken(MeansProcParser.DOT, 0); }
		public LiteralContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_literal; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MeansProcListener ) ((MeansProcListener)listener).enterLiteral(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MeansProcListener ) ((MeansProcListener)listener).exitLiteral(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MeansProcVisitor ) return ((MeansProcVisitor<? extends T>)visitor).visitLiteral(this);
			else return visitor.visitChildren(this);
		}
	}

	public final LiteralContext literal() throws RecognitionException {
		LiteralContext _localctx = new LiteralContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_literal);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(229);
			_la = _input.LA(1);
			if ( !(((((_la - 220)) & ~0x3f) == 0 && ((1L << (_la - 220)) & ((1L << (DateLiteral - 220)) | (1L << (TimeLiteral - 220)) | (1L << (DateTimeLiteral - 220)) | (1L << (BitLiteral - 220)) | (1L << (NameLiteral - 220)) | (1L << (HexLiteral - 220)) | (1L << (STRINGLITERAL - 220)) | (1L << (INT - 220)) | (1L << (FloatingPointLiteral - 220)) | (1L << (DOT - 220)))) != 0)) ) {
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
		public TerminalNode Identifier() { return getToken(MeansProcParser.Identifier, 0); }
		public TerminalNode DATE() { return getToken(MeansProcParser.DATE, 0); }
		public TerminalNode ALTER() { return getToken(MeansProcParser.ALTER, 0); }
		public TerminalNode DROP() { return getToken(MeansProcParser.DROP, 0); }
		public List<VariablesContext> variables() {
			return getRuleContexts(VariablesContext.class);
		}
		public VariablesContext variables(int i) {
			return getRuleContext(VariablesContext.class,i);
		}
		public TerminalNode DOT() { return getToken(MeansProcParser.DOT, 0); }
		public VariablesContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variables; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MeansProcListener ) ((MeansProcListener)listener).enterVariables(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MeansProcListener ) ((MeansProcListener)listener).exitVariables(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MeansProcVisitor ) return ((MeansProcVisitor<? extends T>)visitor).visitVariables(this);
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
		int _startState = 24;
		enterRecursionRule(_localctx, 24, RULE_variables, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(236);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Identifier:
				{
				setState(232);
				match(Identifier);
				}
				break;
			case DATE:
				{
				setState(233);
				match(DATE);
				}
				break;
			case ALTER:
				{
				setState(234);
				match(ALTER);
				}
				break;
			case DROP:
				{
				setState(235);
				match(DROP);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(243);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,26,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new VariablesContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_variables);
					setState(238);
					if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
					setState(239);
					match(DOT);
					setState(240);
					variables(6);
					}
					} 
				}
				setState(245);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,26,_ctx);
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
		case 5:
			return expression_sempred((ExpressionContext)_localctx, predIndex);
		case 6:
			return expressionList_sempred((ExpressionListContext)_localctx, predIndex);
		case 12:
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\u00f0\u00f9\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\3\2\7\2\36\n\2\f\2\16\2!\13\2\3\2\3\2"+
		"\3\3\3\3\3\3\3\3\3\3\3\3\6\3+\n\3\r\3\16\3,\3\3\3\3\3\3\3\3\3\3\3\3\7"+
		"\3\65\n\3\f\3\16\38\13\3\3\3\3\3\5\3<\n\3\3\4\3\4\3\5\3\5\7\5B\n\5\f\5"+
		"\16\5E\13\5\3\6\3\6\3\6\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\5"+
		"\7U\n\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3"+
		"\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7"+
		"\5\7x\n\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\7\7"+
		"\u0088\n\7\f\7\16\7\u008b\13\7\3\b\3\b\3\b\5\b\u0090\n\b\3\b\3\b\3\b\5"+
		"\b\u0095\n\b\7\b\u0097\n\b\f\b\16\b\u009a\13\b\3\b\3\b\6\b\u009e\n\b\r"+
		"\b\16\b\u009f\3\b\7\b\u00a3\n\b\f\b\16\b\u00a6\13\b\3\t\3\t\3\t\3\t\3"+
		"\t\3\t\3\t\5\t\u00af\n\t\3\t\3\t\3\t\7\t\u00b4\n\t\f\t\16\t\u00b7\13\t"+
		"\3\t\3\t\3\t\7\t\u00bc\n\t\f\t\16\t\u00bf\13\t\3\t\3\t\3\t\3\t\3\t\5\t"+
		"\u00c6\n\t\3\n\3\n\3\n\3\n\6\n\u00cc\n\n\r\n\16\n\u00cd\3\13\3\13\3\13"+
		"\3\13\5\13\u00d4\n\13\3\13\3\13\3\13\5\13\u00d9\n\13\7\13\u00db\n\13\f"+
		"\13\16\13\u00de\13\13\3\13\3\13\5\13\u00e2\n\13\3\f\3\f\3\f\3\f\3\r\3"+
		"\r\3\16\3\16\3\16\3\16\3\16\5\16\u00ef\n\16\3\16\3\16\3\16\7\16\u00f4"+
		"\n\16\f\16\16\16\u00f7\13\16\3\16\2\5\f\16\32\17\2\4\6\b\n\f\16\20\22"+
		"\24\26\30\32\2\13\3\2\24\31\4\2\3\3\f\f\3\2\r\17\3\2\20\21\3\2\u00cb\u00d0"+
		"\3\2\u00d2\u00d7\3\2\u00d9\u00da\4\2\u00d1\u00d1\u00d8\u00d8\4\2\u00de"+
		"\u00e6\u00e8\u00e8\2\u011b\2\37\3\2\2\2\4;\3\2\2\2\6=\3\2\2\2\b?\3\2\2"+
		"\2\nF\3\2\2\2\fT\3\2\2\2\16\u008c\3\2\2\2\20\u00c5\3\2\2\2\22\u00cb\3"+
		"\2\2\2\24\u00e1\3\2\2\2\26\u00e3\3\2\2\2\30\u00e7\3\2\2\2\32\u00ee\3\2"+
		"\2\2\34\36\5\4\3\2\35\34\3\2\2\2\36!\3\2\2\2\37\35\3\2\2\2\37 \3\2\2\2"+
		" \"\3\2\2\2!\37\3\2\2\2\"#\7\2\2\3#\3\3\2\2\2$*\7\u00b3\2\2%+\5\32\16"+
		"\2&\'\5\32\16\2\'(\7\3\2\2()\5\32\16\2)+\3\2\2\2*%\3\2\2\2*&\3\2\2\2+"+
		",\3\2\2\2,*\3\2\2\2,-\3\2\2\2-.\3\2\2\2./\7\4\2\2/<\3\2\2\2\60<\7\33\2"+
		"\2\61\62\7\32\2\2\62<\7\u00ea\2\2\63\65\5\6\4\2\64\63\3\2\2\2\658\3\2"+
		"\2\2\66\64\3\2\2\2\66\67\3\2\2\2\679\3\2\2\28\66\3\2\2\29<\7\4\2\2:<\5"+
		"\n\6\2;$\3\2\2\2;\60\3\2\2\2;\61\3\2\2\2;\66\3\2\2\2;:\3\2\2\2<\5\3\2"+
		"\2\2=>\t\2\2\2>\7\3\2\2\2?C\7\u00e7\2\2@B\7\u00e7\2\2A@\3\2\2\2BE\3\2"+
		"\2\2CA\3\2\2\2CD\3\2\2\2D\t\3\2\2\2EC\3\2\2\2FG\5\b\5\2GH\7\4\2\2H\13"+
		"\3\2\2\2IJ\b\7\1\2JU\5\30\r\2KU\7\u00e7\2\2LM\7\5\2\2MN\5\f\7\2NO\7\6"+
		"\2\2OU\3\2\2\2PQ\t\3\2\2QU\5\f\7\16RS\7\u00db\2\2SU\5\f\7\rTI\3\2\2\2"+
		"TK\3\2\2\2TL\3\2\2\2TP\3\2\2\2TR\3\2\2\2U\u0089\3\2\2\2VW\f\17\2\2WX\7"+
		"\13\2\2X\u0088\5\f\7\17YZ\f\f\2\2Z[\7\u00dc\2\2[\u0088\5\f\7\r\\]\f\13"+
		"\2\2]^\7\u00dd\2\2^\u0088\5\f\7\f_`\f\n\2\2`a\t\4\2\2a\u0088\5\f\7\13"+
		"bc\f\t\2\2cd\t\3\2\2d\u0088\5\f\7\nef\f\b\2\2fg\t\5\2\2g\u0088\5\f\7\t"+
		"hi\f\7\2\2ij\t\6\2\2j\u0088\5\f\7\bkl\f\6\2\2lm\t\7\2\2m\u0088\5\f\7\7"+
		"no\f\4\2\2op\t\b\2\2p\u0088\5\f\7\5qr\f\3\2\2rs\7\u00ea\2\2s\u0088\5\f"+
		"\7\3tu\f\22\2\2uw\7\5\2\2vx\5\16\b\2wv\3\2\2\2wx\3\2\2\2xy\3\2\2\2y\u0088"+
		"\7\6\2\2z{\f\21\2\2{|\7\7\2\2|}\5\f\7\2}~\7\b\2\2~\u0088\3\2\2\2\177\u0080"+
		"\f\20\2\2\u0080\u0081\7\t\2\2\u0081\u0082\5\f\7\2\u0082\u0083\7\n\2\2"+
		"\u0083\u0088\3\2\2\2\u0084\u0085\f\5\2\2\u0085\u0086\t\t\2\2\u0086\u0088"+
		"\5\24\13\2\u0087V\3\2\2\2\u0087Y\3\2\2\2\u0087\\\3\2\2\2\u0087_\3\2\2"+
		"\2\u0087b\3\2\2\2\u0087e\3\2\2\2\u0087h\3\2\2\2\u0087k\3\2\2\2\u0087n"+
		"\3\2\2\2\u0087q\3\2\2\2\u0087t\3\2\2\2\u0087z\3\2\2\2\u0087\177\3\2\2"+
		"\2\u0087\u0084\3\2\2\2\u0088\u008b\3\2\2\2\u0089\u0087\3\2\2\2\u0089\u008a"+
		"\3\2\2\2\u008a\r\3\2\2\2\u008b\u0089\3\2\2\2\u008c\u008f\b\b\1\2\u008d"+
		"\u0090\5\f\7\2\u008e\u0090\5\20\t\2\u008f\u008d\3\2\2\2\u008f\u008e\3"+
		"\2\2\2\u0090\u0098\3\2\2\2\u0091\u0094\7\u00eb\2\2\u0092\u0095\5\f\7\2"+
		"\u0093\u0095\5\20\t\2\u0094\u0092\3\2\2\2\u0094\u0093\3\2\2\2\u0095\u0097"+
		"\3\2\2\2\u0096\u0091\3\2\2\2\u0097\u009a\3\2\2\2\u0098\u0096\3\2\2\2\u0098"+
		"\u0099\3\2\2\2\u0099\u00a4\3\2\2\2\u009a\u0098\3\2\2\2\u009b\u009d\f\3"+
		"\2\2\u009c\u009e\7\u00eb\2\2\u009d\u009c\3\2\2\2\u009e\u009f\3\2\2\2\u009f"+
		"\u009d\3\2\2\2\u009f\u00a0\3\2\2\2\u00a0\u00a1\3\2\2\2\u00a1\u00a3\5\16"+
		"\b\4\u00a2\u009b\3\2\2\2\u00a3\u00a6\3\2\2\2\u00a4\u00a2\3\2\2\2\u00a4"+
		"\u00a5\3\2\2\2\u00a5\17\3\2\2\2\u00a6\u00a4\3\2\2\2\u00a7\u00a8\7\22\2"+
		"\2\u00a8\u00a9\7\u00e7\2\2\u00a9\u00aa\7\3\2\2\u00aa\u00ab\7\u00e7\2\2"+
		"\u00ab\u00b5\3\2\2\2\u00ac\u00ad\7\u00eb\2\2\u00ad\u00af\7\22\2\2\u00ae"+
		"\u00ac\3\2\2\2\u00ae\u00af\3\2\2\2\u00af\u00b0\3\2\2\2\u00b0\u00b1\7\u00e7"+
		"\2\2\u00b1\u00b2\7\3\2\2\u00b2\u00b4\7\u00e7\2\2\u00b3\u00ae\3\2\2\2\u00b4"+
		"\u00b7\3\2\2\2\u00b5\u00b3\3\2\2\2\u00b5\u00b6\3\2\2\2\u00b6\u00c6\3\2"+
		"\2\2\u00b7\u00b5\3\2\2\2\u00b8\u00b9\7\22\2\2\u00b9\u00bd\7\u00e7\2\2"+
		"\u00ba\u00bc\7\u00e7\2\2\u00bb\u00ba\3\2\2\2\u00bc\u00bf\3\2\2\2\u00bd"+
		"\u00bb\3\2\2\2\u00bd\u00be\3\2\2\2\u00be\u00c6\3\2\2\2\u00bf\u00bd\3\2"+
		"\2\2\u00c0\u00c1\7\22\2\2\u00c1\u00c2\7\u00e7\2\2\u00c2\u00c3\7\t\2\2"+
		"\u00c3\u00c4\7\r\2\2\u00c4\u00c6\7\n\2\2\u00c5\u00a7\3\2\2\2\u00c5\u00b8"+
		"\3\2\2\2\u00c5\u00c0\3\2\2\2\u00c6\21\3\2\2\2\u00c7\u00cc\7\u00e7\2\2"+
		"\u00c8\u00c9\7\u00e7\2\2\u00c9\u00ca\7\3\2\2\u00ca\u00cc\7\u00e7\2\2\u00cb"+
		"\u00c7\3\2\2\2\u00cb\u00c8\3\2\2\2\u00cc\u00cd\3\2\2\2\u00cd\u00cb\3\2"+
		"\2\2\u00cd\u00ce\3\2\2\2\u00ce\23\3\2\2\2\u00cf\u00e2\7\u00e7\2\2\u00d0"+
		"\u00d3\7\5\2\2\u00d1\u00d4\5\30\r\2\u00d2\u00d4\5\26\f\2\u00d3\u00d1\3"+
		"\2\2\2\u00d3\u00d2\3\2\2\2\u00d4\u00dc\3\2\2\2\u00d5\u00d8\7\u00eb\2\2"+
		"\u00d6\u00d9\5\30\r\2\u00d7\u00d9\5\26\f\2\u00d8\u00d6\3\2\2\2\u00d8\u00d7"+
		"\3\2\2\2\u00d9\u00db\3\2\2\2\u00da\u00d5\3\2\2\2\u00db\u00de\3\2\2\2\u00dc"+
		"\u00da\3\2\2\2\u00dc\u00dd\3\2\2\2\u00dd\u00df\3\2\2\2\u00de\u00dc\3\2"+
		"\2\2\u00df\u00e0\7\6\2\2\u00e0\u00e2\3\2\2\2\u00e1\u00cf\3\2\2\2\u00e1"+
		"\u00d0\3\2\2\2\u00e2\25\3\2\2\2\u00e3\u00e4\7\u00e5\2\2\u00e4\u00e5\7"+
		"\23\2\2\u00e5\u00e6\7\u00e5\2\2\u00e6\27\3\2\2\2\u00e7\u00e8\t\n\2\2\u00e8"+
		"\31\3\2\2\2\u00e9\u00ea\b\16\1\2\u00ea\u00ef\7\u00e7\2\2\u00eb\u00ef\7"+
		"\u00ae\2\2\u00ec\u00ef\7\u0096\2\2\u00ed\u00ef\7\u00b3\2\2\u00ee\u00e9"+
		"\3\2\2\2\u00ee\u00eb\3\2\2\2\u00ee\u00ec\3\2\2\2\u00ee\u00ed\3\2\2\2\u00ef"+
		"\u00f5\3\2\2\2\u00f0\u00f1\f\7\2\2\u00f1\u00f2\7\u00e8\2\2\u00f2\u00f4"+
		"\5\32\16\b\u00f3\u00f0\3\2\2\2\u00f4\u00f7\3\2\2\2\u00f5\u00f3\3\2\2\2"+
		"\u00f5\u00f6\3\2\2\2\u00f6\33\3\2\2\2\u00f7\u00f5\3\2\2\2\35\37*,\66;"+
		"CTw\u0087\u0089\u008f\u0094\u0098\u009f\u00a4\u00ae\u00b5\u00bd\u00c5"+
		"\u00cb\u00cd\u00d3\u00d8\u00dc\u00e1\u00ee\u00f5";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}