// Generated from FreqProc.g4 by ANTLR 4.8
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class FreqProcParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, T__16=17, 
		EXACT=18, TABLES=19, TEST=20, WEIGHT=21, ABEND=22, END=23, LENGTH=24, 
		QKUPCASE=25, SYSEVALF=26, ABORT=27, EVAL=28, LET=29, QSCAN=30, SYSEXEC=31, 
		ACT=32, FILE=33, LIST=34, QSUBSTR=35, SYSFUNC=36, ACTIVATE=37, GLOBAL=38, 
		LISTM=39, QSYSFUNC=40, SYSGET=41, BQUOTE=42, GO=43, LOCAL=44, QUOTE=45, 
		SYSRPUT=46, BY=47, GOTO=48, MACRO=49, QUPCASE=50, THEN=51, CLEAR=52, IF=53, 
		MEND=54, RESOLVE=55, TO=56, CLOSE=57, INC=58, PAUSE=59, RETURN=60, TSO=61, 
		CMS=62, INCLUDE=63, NRSTR=64, RUN=65, UNQUOTE=66, COMANDR=67, INDEX=68, 
		ON=69, SAVE=70, UNSTR=71, COPY=72, INFILE=73, OPEN=74, SCAN=75, UNTIL=76, 
		DEACT=77, INPUT=78, PUT=79, STOP=80, UPCASE=81, DEL=82, KCMPRES=83, NRBQUOTE=84, 
		STR=85, WHILE=86, DELETE=87, KINDEX=88, NRQUOTE=89, SYSCALL=90, WINDOW=91, 
		DISPLAY=92, KLEFT=93, METASYM=94, SUBSTR=95, DMIDSPLY=96, KLENGTH=97, 
		QKCMPRES=98, SUPERQ=99, DMISPLIT=100, KSCAN=101, QKLEFT=102, SYMDEL=103, 
		DO=104, KSUBSTR=105, QKSCAN=106, SYMEXIST=107, EDIT=108, KTRIM=109, QKSUBSTR=110, 
		SYMGLOBL=111, ELSE=112, KUPCASE=113, QKTRIM=114, SYMLOCAL=115, Tk_NULL=116, 
		CANCEL=117, NOLIST=118, ARRAY=119, ARRAY_NUMERIC_ELEMENTS=120, ARRAY_CHARACTER_ELEMENTS=121, 
		ARRAY_ALL_ELEMENTS=122, GROUPFORMAT=123, NOTSORTED=124, DESCENDING=125, 
		CALL=126, DEBUG=127, NESTING=128, STACK=129, READ=130, PW=131, SOURCE=132, 
		VIEW=133, PGM=134, ENCRYPT=135, NOSAVE=136, DATALINES=137, CARDS=138, 
		LINES=139, DATALINES4=140, CARDS4=141, LINES4=142, END_DATALINES4=143, 
		ALTER=144, DISK=145, DUMMY=146, GTERM=147, PIPE=148, PLOTTER=149, PRINTER=150, 
		TAPE=151, TEMP=152, TERMINAL=153, UPRINTER=154, DSD=155, EXPANDTABS=156, 
		NOEXPANDTABS=157, FLOWOVER=158, MISSOVER=159, PAD=160, NOPAD=161, SCANOVER=162, 
		SHAREBUFFERS=163, STOPOVER=164, TRUNCOVER=165, V_INFILE_=166, INPUT_ODS=167, 
		DATE=168, DATETIME=169, DDMMYY=170, INFORMAT_COMMA=171, INFORMAT_CHAR=172, 
		DROP=173, PROC=174, ANOVA=175, MEANS=176, REG=177, CORR=178, SGPLOT=179, 
		PRINT=180, DATA=181, GLM=182, FREQ=183, SQL=184, UNIVARIATE=185, NPAR1WAY=186, 
		IMPORT=187, SORT=188, DATASETS=189, TABULATE=190, RANK=191, CHART=192, 
		LOGISTIC=193, SURVEYSELECT=194, Informat=195, DOLLAR=196, EQ=197, NE=198, 
		GT=199, LT=200, GE=201, LE=202, IN=203, EQC=204, NEC=205, GTC=206, LTC=207, 
		GEC=208, LEC=209, INColon=210, AND=211, OR=212, NOT=213, MIN=214, MAX=215, 
		DateLiteral=216, TimeLiteral=217, DateTimeLiteral=218, BitLiteral=219, 
		NameLiteral=220, HexLiteral=221, STRINGLITERAL=222, INT=223, FloatingPointLiteral=224, 
		Identifier=225, DOT=226, AT=227, EQUAL=228, COMMA=229, LBracket=230, RBracket=231, 
		WS=232, COMMENT=233, LINE_COMMENT=234;
	public static final int
		RULE_freq_main = 0, RULE_freq_proc = 1, RULE_expression = 2, RULE_expressionList = 3, 
		RULE_of_var_list = 4, RULE_identifiers_list = 5, RULE_in_var_list = 6, 
		RULE_colonInts = 7, RULE_literal = 8, RULE_variables = 9;
	private static String[] makeRuleNames() {
		return new String[] {
			"freq_main", "freq_proc", "expression", "expressionList", "of_var_list", 
			"identifiers_list", "in_var_list", "colonInts", "literal", "variables"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "';'", "'('", "')'", "'{'", "'}'", "'['", "']'", "'**'", "'+'", 
			"'-'", "'*'", "'/'", "'%'", "'||'", "'!!'", "'of'", "':'", null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, "';;;;'", null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, "'$'", null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, "'><'", "'<>'", null, null, null, null, null, null, 
			null, null, null, null, "'.'", "'@'", "'='", "','"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, "EXACT", "TABLES", "TEST", "WEIGHT", 
			"ABEND", "END", "LENGTH", "QKUPCASE", "SYSEVALF", "ABORT", "EVAL", "LET", 
			"QSCAN", "SYSEXEC", "ACT", "FILE", "LIST", "QSUBSTR", "SYSFUNC", "ACTIVATE", 
			"GLOBAL", "LISTM", "QSYSFUNC", "SYSGET", "BQUOTE", "GO", "LOCAL", "QUOTE", 
			"SYSRPUT", "BY", "GOTO", "MACRO", "QUPCASE", "THEN", "CLEAR", "IF", "MEND", 
			"RESOLVE", "TO", "CLOSE", "INC", "PAUSE", "RETURN", "TSO", "CMS", "INCLUDE", 
			"NRSTR", "RUN", "UNQUOTE", "COMANDR", "INDEX", "ON", "SAVE", "UNSTR", 
			"COPY", "INFILE", "OPEN", "SCAN", "UNTIL", "DEACT", "INPUT", "PUT", "STOP", 
			"UPCASE", "DEL", "KCMPRES", "NRBQUOTE", "STR", "WHILE", "DELETE", "KINDEX", 
			"NRQUOTE", "SYSCALL", "WINDOW", "DISPLAY", "KLEFT", "METASYM", "SUBSTR", 
			"DMIDSPLY", "KLENGTH", "QKCMPRES", "SUPERQ", "DMISPLIT", "KSCAN", "QKLEFT", 
			"SYMDEL", "DO", "KSUBSTR", "QKSCAN", "SYMEXIST", "EDIT", "KTRIM", "QKSUBSTR", 
			"SYMGLOBL", "ELSE", "KUPCASE", "QKTRIM", "SYMLOCAL", "Tk_NULL", "CANCEL", 
			"NOLIST", "ARRAY", "ARRAY_NUMERIC_ELEMENTS", "ARRAY_CHARACTER_ELEMENTS", 
			"ARRAY_ALL_ELEMENTS", "GROUPFORMAT", "NOTSORTED", "DESCENDING", "CALL", 
			"DEBUG", "NESTING", "STACK", "READ", "PW", "SOURCE", "VIEW", "PGM", "ENCRYPT", 
			"NOSAVE", "DATALINES", "CARDS", "LINES", "DATALINES4", "CARDS4", "LINES4", 
			"END_DATALINES4", "ALTER", "DISK", "DUMMY", "GTERM", "PIPE", "PLOTTER", 
			"PRINTER", "TAPE", "TEMP", "TERMINAL", "UPRINTER", "DSD", "EXPANDTABS", 
			"NOEXPANDTABS", "FLOWOVER", "MISSOVER", "PAD", "NOPAD", "SCANOVER", "SHAREBUFFERS", 
			"STOPOVER", "TRUNCOVER", "V_INFILE_", "INPUT_ODS", "DATE", "DATETIME", 
			"DDMMYY", "INFORMAT_COMMA", "INFORMAT_CHAR", "DROP", "PROC", "ANOVA", 
			"MEANS", "REG", "CORR", "SGPLOT", "PRINT", "DATA", "GLM", "FREQ", "SQL", 
			"UNIVARIATE", "NPAR1WAY", "IMPORT", "SORT", "DATASETS", "TABULATE", "RANK", 
			"CHART", "LOGISTIC", "SURVEYSELECT", "Informat", "DOLLAR", "EQ", "NE", 
			"GT", "LT", "GE", "LE", "IN", "EQC", "NEC", "GTC", "LTC", "GEC", "LEC", 
			"INColon", "AND", "OR", "NOT", "MIN", "MAX", "DateLiteral", "TimeLiteral", 
			"DateTimeLiteral", "BitLiteral", "NameLiteral", "HexLiteral", "STRINGLITERAL", 
			"INT", "FloatingPointLiteral", "Identifier", "DOT", "AT", "EQUAL", "COMMA", 
			"LBracket", "RBracket", "WS", "COMMENT", "LINE_COMMENT"
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
	public String getGrammarFileName() { return "FreqProc.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public FreqProcParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class Freq_mainContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(FreqProcParser.EOF, 0); }
		public List<Freq_procContext> freq_proc() {
			return getRuleContexts(Freq_procContext.class);
		}
		public Freq_procContext freq_proc(int i) {
			return getRuleContext(Freq_procContext.class,i);
		}
		public Freq_mainContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_freq_main; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof FreqProcListener ) ((FreqProcListener)listener).enterFreq_main(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof FreqProcListener ) ((FreqProcListener)listener).exitFreq_main(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FreqProcVisitor ) return ((FreqProcVisitor<? extends T>)visitor).visitFreq_main(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Freq_mainContext freq_main() throws RecognitionException {
		Freq_mainContext _localctx = new Freq_mainContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_freq_main);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(23);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << EXACT) | (1L << TABLES) | (1L << TEST) | (1L << WEIGHT) | (1L << BY))) != 0)) {
				{
				{
				setState(20);
				freq_proc();
				}
				}
				setState(25);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(26);
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

	public static class Freq_procContext extends ParserRuleContext {
		public TerminalNode BY() { return getToken(FreqProcParser.BY, 0); }
		public VariablesContext variables() {
			return getRuleContext(VariablesContext.class,0);
		}
		public TerminalNode EXACT() { return getToken(FreqProcParser.EXACT, 0); }
		public TerminalNode TABLES() { return getToken(FreqProcParser.TABLES, 0); }
		public TerminalNode TEST() { return getToken(FreqProcParser.TEST, 0); }
		public TerminalNode WEIGHT() { return getToken(FreqProcParser.WEIGHT, 0); }
		public Freq_procContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_freq_proc; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof FreqProcListener ) ((FreqProcListener)listener).enterFreq_proc(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof FreqProcListener ) ((FreqProcListener)listener).exitFreq_proc(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FreqProcVisitor ) return ((FreqProcVisitor<? extends T>)visitor).visitFreq_proc(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Freq_procContext freq_proc() throws RecognitionException {
		Freq_procContext _localctx = new Freq_procContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_freq_proc);
		try {
			setState(48);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case BY:
				enterOuterAlt(_localctx, 1);
				{
				setState(28);
				match(BY);
				setState(29);
				variables(0);
				setState(30);
				match(T__0);
				}
				break;
			case EXACT:
				enterOuterAlt(_localctx, 2);
				{
				setState(32);
				match(EXACT);
				setState(33);
				variables(0);
				setState(34);
				match(T__0);
				}
				break;
			case TABLES:
				enterOuterAlt(_localctx, 3);
				{
				setState(36);
				match(TABLES);
				setState(37);
				variables(0);
				setState(38);
				match(T__0);
				}
				break;
			case TEST:
				enterOuterAlt(_localctx, 4);
				{
				setState(40);
				match(TEST);
				setState(41);
				variables(0);
				setState(42);
				match(T__0);
				}
				break;
			case WEIGHT:
				enterOuterAlt(_localctx, 5);
				{
				setState(44);
				match(WEIGHT);
				setState(45);
				variables(0);
				setState(46);
				match(T__0);
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

	public static class ExpressionContext extends ParserRuleContext {
		public LiteralContext literal() {
			return getRuleContext(LiteralContext.class,0);
		}
		public TerminalNode Identifier() { return getToken(FreqProcParser.Identifier, 0); }
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode NOT() { return getToken(FreqProcParser.NOT, 0); }
		public TerminalNode MIN() { return getToken(FreqProcParser.MIN, 0); }
		public TerminalNode MAX() { return getToken(FreqProcParser.MAX, 0); }
		public TerminalNode EQ() { return getToken(FreqProcParser.EQ, 0); }
		public TerminalNode NE() { return getToken(FreqProcParser.NE, 0); }
		public TerminalNode GT() { return getToken(FreqProcParser.GT, 0); }
		public TerminalNode LT() { return getToken(FreqProcParser.LT, 0); }
		public TerminalNode GE() { return getToken(FreqProcParser.GE, 0); }
		public TerminalNode LE() { return getToken(FreqProcParser.LE, 0); }
		public TerminalNode EQC() { return getToken(FreqProcParser.EQC, 0); }
		public TerminalNode NEC() { return getToken(FreqProcParser.NEC, 0); }
		public TerminalNode GTC() { return getToken(FreqProcParser.GTC, 0); }
		public TerminalNode LTC() { return getToken(FreqProcParser.LTC, 0); }
		public TerminalNode GEC() { return getToken(FreqProcParser.GEC, 0); }
		public TerminalNode LEC() { return getToken(FreqProcParser.LEC, 0); }
		public TerminalNode AND() { return getToken(FreqProcParser.AND, 0); }
		public TerminalNode OR() { return getToken(FreqProcParser.OR, 0); }
		public TerminalNode EQUAL() { return getToken(FreqProcParser.EQUAL, 0); }
		public ExpressionListContext expressionList() {
			return getRuleContext(ExpressionListContext.class,0);
		}
		public In_var_listContext in_var_list() {
			return getRuleContext(In_var_listContext.class,0);
		}
		public TerminalNode IN() { return getToken(FreqProcParser.IN, 0); }
		public TerminalNode INColon() { return getToken(FreqProcParser.INColon, 0); }
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof FreqProcListener ) ((FreqProcListener)listener).enterExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof FreqProcListener ) ((FreqProcListener)listener).exitExpression(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FreqProcVisitor ) return ((FreqProcVisitor<? extends T>)visitor).visitExpression(this);
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
		int _startState = 4;
		enterRecursionRule(_localctx, 4, RULE_expression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(61);
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
				setState(51);
				literal();
				}
				break;
			case Identifier:
				{
				setState(52);
				match(Identifier);
				}
				break;
			case T__1:
				{
				setState(53);
				match(T__1);
				setState(54);
				expression(0);
				setState(55);
				match(T__2);
				}
				break;
			case T__8:
			case T__9:
				{
				setState(57);
				_la = _input.LA(1);
				if ( !(_la==T__8 || _la==T__9) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(58);
				expression(12);
				}
				break;
			case NOT:
				{
				setState(59);
				match(NOT);
				setState(60);
				expression(11);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(114);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,5,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(112);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
					case 1:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(63);
						if (!(precpred(_ctx, 13))) throw new FailedPredicateException(this, "precpred(_ctx, 13)");
						setState(64);
						match(T__7);
						setState(65);
						expression(13);
						}
						break;
					case 2:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(66);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(67);
						match(MIN);
						setState(68);
						expression(11);
						}
						break;
					case 3:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(69);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(70);
						match(MAX);
						setState(71);
						expression(10);
						}
						break;
					case 4:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(72);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(73);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__10) | (1L << T__11) | (1L << T__12))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(74);
						expression(9);
						}
						break;
					case 5:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(75);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(76);
						_la = _input.LA(1);
						if ( !(_la==T__8 || _la==T__9) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(77);
						expression(8);
						}
						break;
					case 6:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(78);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(79);
						_la = _input.LA(1);
						if ( !(_la==T__13 || _la==T__14) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(80);
						expression(7);
						}
						break;
					case 7:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(81);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(82);
						_la = _input.LA(1);
						if ( !(((((_la - 197)) & ~0x3f) == 0 && ((1L << (_la - 197)) & ((1L << (EQ - 197)) | (1L << (NE - 197)) | (1L << (GT - 197)) | (1L << (LT - 197)) | (1L << (GE - 197)) | (1L << (LE - 197)))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(83);
						expression(6);
						}
						break;
					case 8:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(84);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(85);
						_la = _input.LA(1);
						if ( !(((((_la - 204)) & ~0x3f) == 0 && ((1L << (_la - 204)) & ((1L << (EQC - 204)) | (1L << (NEC - 204)) | (1L << (GTC - 204)) | (1L << (LTC - 204)) | (1L << (GEC - 204)) | (1L << (LEC - 204)))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(86);
						expression(5);
						}
						break;
					case 9:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(87);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(88);
						_la = _input.LA(1);
						if ( !(_la==AND || _la==OR) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(89);
						expression(3);
						}
						break;
					case 10:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(90);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(91);
						match(EQUAL);
						setState(92);
						expression(1);
						}
						break;
					case 11:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(93);
						if (!(precpred(_ctx, 16))) throw new FailedPredicateException(this, "precpred(_ctx, 16)");
						setState(94);
						match(T__1);
						setState(96);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__1) | (1L << T__8) | (1L << T__9) | (1L << T__15))) != 0) || ((((_la - 213)) & ~0x3f) == 0 && ((1L << (_la - 213)) & ((1L << (NOT - 213)) | (1L << (DateLiteral - 213)) | (1L << (TimeLiteral - 213)) | (1L << (DateTimeLiteral - 213)) | (1L << (BitLiteral - 213)) | (1L << (NameLiteral - 213)) | (1L << (HexLiteral - 213)) | (1L << (STRINGLITERAL - 213)) | (1L << (INT - 213)) | (1L << (FloatingPointLiteral - 213)) | (1L << (Identifier - 213)) | (1L << (DOT - 213)))) != 0)) {
							{
							setState(95);
							expressionList(0);
							}
						}

						setState(98);
						match(T__2);
						}
						break;
					case 12:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(99);
						if (!(precpred(_ctx, 15))) throw new FailedPredicateException(this, "precpred(_ctx, 15)");
						setState(100);
						match(T__3);
						setState(101);
						expression(0);
						setState(102);
						match(T__4);
						}
						break;
					case 13:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(104);
						if (!(precpred(_ctx, 14))) throw new FailedPredicateException(this, "precpred(_ctx, 14)");
						setState(105);
						match(T__5);
						setState(106);
						expression(0);
						setState(107);
						match(T__6);
						}
						break;
					case 14:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(109);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(110);
						_la = _input.LA(1);
						if ( !(_la==IN || _la==INColon) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(111);
						in_var_list();
						}
						break;
					}
					} 
				}
				setState(116);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,5,_ctx);
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
		public List<TerminalNode> COMMA() { return getTokens(FreqProcParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(FreqProcParser.COMMA, i);
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
			if ( listener instanceof FreqProcListener ) ((FreqProcListener)listener).enterExpressionList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof FreqProcListener ) ((FreqProcListener)listener).exitExpressionList(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FreqProcVisitor ) return ((FreqProcVisitor<? extends T>)visitor).visitExpressionList(this);
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
		int _startState = 6;
		enterRecursionRule(_localctx, 6, RULE_expressionList, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(120);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__1:
			case T__8:
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
				setState(118);
				expression(0);
				}
				break;
			case T__15:
				{
				setState(119);
				of_var_list();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(129);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(122);
					match(COMMA);
					setState(125);
					_errHandler.sync(this);
					switch (_input.LA(1)) {
					case T__1:
					case T__8:
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
						setState(123);
						expression(0);
						}
						break;
					case T__15:
						{
						setState(124);
						of_var_list();
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					}
					} 
				}
				setState(131);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
			}
			}
			_ctx.stop = _input.LT(-1);
			setState(141);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ExpressionListContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_expressionList);
					setState(132);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(134); 
					_errHandler.sync(this);
					_la = _input.LA(1);
					do {
						{
						{
						setState(133);
						match(COMMA);
						}
						}
						setState(136); 
						_errHandler.sync(this);
						_la = _input.LA(1);
					} while ( _la==COMMA );
					setState(138);
					expressionList(2);
					}
					} 
				}
				setState(143);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
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
		public List<TerminalNode> Identifier() { return getTokens(FreqProcParser.Identifier); }
		public TerminalNode Identifier(int i) {
			return getToken(FreqProcParser.Identifier, i);
		}
		public List<TerminalNode> COMMA() { return getTokens(FreqProcParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(FreqProcParser.COMMA, i);
		}
		public Of_var_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_of_var_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof FreqProcListener ) ((FreqProcListener)listener).enterOf_var_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof FreqProcListener ) ((FreqProcListener)listener).exitOf_var_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FreqProcVisitor ) return ((FreqProcVisitor<? extends T>)visitor).visitOf_var_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Of_var_listContext of_var_list() throws RecognitionException {
		Of_var_listContext _localctx = new Of_var_listContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_of_var_list);
		int _la;
		try {
			int _alt;
			setState(174);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(144);
				match(T__15);
				{
				setState(145);
				match(Identifier);
				setState(146);
				match(T__9);
				setState(147);
				match(Identifier);
				}
				setState(158);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(151);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if (_la==COMMA) {
							{
							setState(149);
							match(COMMA);
							setState(150);
							match(T__15);
							}
						}

						{
						setState(153);
						match(Identifier);
						setState(154);
						match(T__9);
						setState(155);
						match(Identifier);
						}
						}
						} 
					}
					setState(160);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(161);
				match(T__15);
				setState(162);
				match(Identifier);
				setState(166);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(163);
						match(Identifier);
						}
						} 
					}
					setState(168);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(169);
				match(T__15);
				setState(170);
				match(Identifier);
				setState(171);
				match(T__5);
				setState(172);
				match(T__10);
				setState(173);
				match(T__6);
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
		public List<TerminalNode> Identifier() { return getTokens(FreqProcParser.Identifier); }
		public TerminalNode Identifier(int i) {
			return getToken(FreqProcParser.Identifier, i);
		}
		public Identifiers_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_identifiers_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof FreqProcListener ) ((FreqProcListener)listener).enterIdentifiers_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof FreqProcListener ) ((FreqProcListener)listener).exitIdentifiers_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FreqProcVisitor ) return ((FreqProcVisitor<? extends T>)visitor).visitIdentifiers_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Identifiers_listContext identifiers_list() throws RecognitionException {
		Identifiers_listContext _localctx = new Identifiers_listContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_identifiers_list);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(180); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				setState(180);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
				case 1:
					{
					setState(176);
					match(Identifier);
					}
					break;
				case 2:
					{
					setState(177);
					match(Identifier);
					setState(178);
					match(T__9);
					setState(179);
					match(Identifier);
					}
					break;
				}
				}
				setState(182); 
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
		public TerminalNode Identifier() { return getToken(FreqProcParser.Identifier, 0); }
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
		public List<TerminalNode> COMMA() { return getTokens(FreqProcParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(FreqProcParser.COMMA, i);
		}
		public In_var_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_in_var_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof FreqProcListener ) ((FreqProcListener)listener).enterIn_var_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof FreqProcListener ) ((FreqProcListener)listener).exitIn_var_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FreqProcVisitor ) return ((FreqProcVisitor<? extends T>)visitor).visitIn_var_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final In_var_listContext in_var_list() throws RecognitionException {
		In_var_listContext _localctx = new In_var_listContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_in_var_list);
		int _la;
		try {
			setState(202);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Identifier:
				enterOuterAlt(_localctx, 1);
				{
				setState(184);
				match(Identifier);
				}
				break;
			case T__1:
				enterOuterAlt(_localctx, 2);
				{
				setState(185);
				match(T__1);
				setState(188);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
				case 1:
					{
					setState(186);
					literal();
					}
					break;
				case 2:
					{
					setState(187);
					colonInts();
					}
					break;
				}
				setState(197);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMMA) {
					{
					{
					setState(190);
					match(COMMA);
					setState(193);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
					case 1:
						{
						setState(191);
						literal();
						}
						break;
					case 2:
						{
						setState(192);
						colonInts();
						}
						break;
					}
					}
					}
					setState(199);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(200);
				match(T__2);
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
		public List<TerminalNode> INT() { return getTokens(FreqProcParser.INT); }
		public TerminalNode INT(int i) {
			return getToken(FreqProcParser.INT, i);
		}
		public ColonIntsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_colonInts; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof FreqProcListener ) ((FreqProcListener)listener).enterColonInts(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof FreqProcListener ) ((FreqProcListener)listener).exitColonInts(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FreqProcVisitor ) return ((FreqProcVisitor<? extends T>)visitor).visitColonInts(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ColonIntsContext colonInts() throws RecognitionException {
		ColonIntsContext _localctx = new ColonIntsContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_colonInts);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(204);
			match(INT);
			setState(205);
			match(T__16);
			setState(206);
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
		public TerminalNode INT() { return getToken(FreqProcParser.INT, 0); }
		public TerminalNode FloatingPointLiteral() { return getToken(FreqProcParser.FloatingPointLiteral, 0); }
		public TerminalNode STRINGLITERAL() { return getToken(FreqProcParser.STRINGLITERAL, 0); }
		public TerminalNode DateLiteral() { return getToken(FreqProcParser.DateLiteral, 0); }
		public TerminalNode TimeLiteral() { return getToken(FreqProcParser.TimeLiteral, 0); }
		public TerminalNode DateTimeLiteral() { return getToken(FreqProcParser.DateTimeLiteral, 0); }
		public TerminalNode BitLiteral() { return getToken(FreqProcParser.BitLiteral, 0); }
		public TerminalNode NameLiteral() { return getToken(FreqProcParser.NameLiteral, 0); }
		public TerminalNode HexLiteral() { return getToken(FreqProcParser.HexLiteral, 0); }
		public TerminalNode DOT() { return getToken(FreqProcParser.DOT, 0); }
		public LiteralContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_literal; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof FreqProcListener ) ((FreqProcListener)listener).enterLiteral(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof FreqProcListener ) ((FreqProcListener)listener).exitLiteral(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FreqProcVisitor ) return ((FreqProcVisitor<? extends T>)visitor).visitLiteral(this);
			else return visitor.visitChildren(this);
		}
	}

	public final LiteralContext literal() throws RecognitionException {
		LiteralContext _localctx = new LiteralContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_literal);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(208);
			_la = _input.LA(1);
			if ( !(((((_la - 216)) & ~0x3f) == 0 && ((1L << (_la - 216)) & ((1L << (DateLiteral - 216)) | (1L << (TimeLiteral - 216)) | (1L << (DateTimeLiteral - 216)) | (1L << (BitLiteral - 216)) | (1L << (NameLiteral - 216)) | (1L << (HexLiteral - 216)) | (1L << (STRINGLITERAL - 216)) | (1L << (INT - 216)) | (1L << (FloatingPointLiteral - 216)) | (1L << (DOT - 216)))) != 0)) ) {
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
		public TerminalNode Identifier() { return getToken(FreqProcParser.Identifier, 0); }
		public TerminalNode DATE() { return getToken(FreqProcParser.DATE, 0); }
		public TerminalNode ALTER() { return getToken(FreqProcParser.ALTER, 0); }
		public TerminalNode DROP() { return getToken(FreqProcParser.DROP, 0); }
		public List<VariablesContext> variables() {
			return getRuleContexts(VariablesContext.class);
		}
		public VariablesContext variables(int i) {
			return getRuleContext(VariablesContext.class,i);
		}
		public TerminalNode DOT() { return getToken(FreqProcParser.DOT, 0); }
		public VariablesContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variables; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof FreqProcListener ) ((FreqProcListener)listener).enterVariables(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof FreqProcListener ) ((FreqProcListener)listener).exitVariables(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FreqProcVisitor ) return ((FreqProcVisitor<? extends T>)visitor).visitVariables(this);
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
		int _startState = 18;
		enterRecursionRule(_localctx, 18, RULE_variables, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(215);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Identifier:
				{
				setState(211);
				match(Identifier);
				}
				break;
			case DATE:
				{
				setState(212);
				match(DATE);
				}
				break;
			case ALTER:
				{
				setState(213);
				match(ALTER);
				}
				break;
			case DROP:
				{
				setState(214);
				match(DROP);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(222);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new VariablesContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_variables);
					setState(217);
					if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
					setState(218);
					match(DOT);
					setState(219);
					variables(6);
					}
					} 
				}
				setState(224);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
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
		case 2:
			return expression_sempred((ExpressionContext)_localctx, predIndex);
		case 3:
			return expressionList_sempred((ExpressionListContext)_localctx, predIndex);
		case 9:
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\u00ec\u00e4\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\3\2\7\2\30\n\2\f\2\16\2\33\13\2\3\2\3\2\3\3\3\3\3\3\3\3\3\3\3\3"+
		"\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\5\3\63\n\3\3"+
		"\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\5\4@\n\4\3\4\3\4\3\4\3\4\3"+
		"\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4"+
		"\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\5\4c\n\4\3\4\3\4\3\4\3\4"+
		"\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\7\4s\n\4\f\4\16\4v\13\4\3\5\3"+
		"\5\3\5\5\5{\n\5\3\5\3\5\3\5\5\5\u0080\n\5\7\5\u0082\n\5\f\5\16\5\u0085"+
		"\13\5\3\5\3\5\6\5\u0089\n\5\r\5\16\5\u008a\3\5\7\5\u008e\n\5\f\5\16\5"+
		"\u0091\13\5\3\6\3\6\3\6\3\6\3\6\3\6\3\6\5\6\u009a\n\6\3\6\3\6\3\6\7\6"+
		"\u009f\n\6\f\6\16\6\u00a2\13\6\3\6\3\6\3\6\7\6\u00a7\n\6\f\6\16\6\u00aa"+
		"\13\6\3\6\3\6\3\6\3\6\3\6\5\6\u00b1\n\6\3\7\3\7\3\7\3\7\6\7\u00b7\n\7"+
		"\r\7\16\7\u00b8\3\b\3\b\3\b\3\b\5\b\u00bf\n\b\3\b\3\b\3\b\5\b\u00c4\n"+
		"\b\7\b\u00c6\n\b\f\b\16\b\u00c9\13\b\3\b\3\b\5\b\u00cd\n\b\3\t\3\t\3\t"+
		"\3\t\3\n\3\n\3\13\3\13\3\13\3\13\3\13\5\13\u00da\n\13\3\13\3\13\3\13\7"+
		"\13\u00df\n\13\f\13\16\13\u00e2\13\13\3\13\2\5\6\b\24\f\2\4\6\b\n\f\16"+
		"\20\22\24\2\n\3\2\13\f\3\2\r\17\3\2\20\21\3\2\u00c7\u00cc\3\2\u00ce\u00d3"+
		"\3\2\u00d5\u00d6\4\2\u00cd\u00cd\u00d4\u00d4\4\2\u00da\u00e2\u00e4\u00e4"+
		"\2\u0105\2\31\3\2\2\2\4\62\3\2\2\2\6?\3\2\2\2\bw\3\2\2\2\n\u00b0\3\2\2"+
		"\2\f\u00b6\3\2\2\2\16\u00cc\3\2\2\2\20\u00ce\3\2\2\2\22\u00d2\3\2\2\2"+
		"\24\u00d9\3\2\2\2\26\30\5\4\3\2\27\26\3\2\2\2\30\33\3\2\2\2\31\27\3\2"+
		"\2\2\31\32\3\2\2\2\32\34\3\2\2\2\33\31\3\2\2\2\34\35\7\2\2\3\35\3\3\2"+
		"\2\2\36\37\7\61\2\2\37 \5\24\13\2 !\7\3\2\2!\63\3\2\2\2\"#\7\24\2\2#$"+
		"\5\24\13\2$%\7\3\2\2%\63\3\2\2\2&\'\7\25\2\2\'(\5\24\13\2()\7\3\2\2)\63"+
		"\3\2\2\2*+\7\26\2\2+,\5\24\13\2,-\7\3\2\2-\63\3\2\2\2./\7\27\2\2/\60\5"+
		"\24\13\2\60\61\7\3\2\2\61\63\3\2\2\2\62\36\3\2\2\2\62\"\3\2\2\2\62&\3"+
		"\2\2\2\62*\3\2\2\2\62.\3\2\2\2\63\5\3\2\2\2\64\65\b\4\1\2\65@\5\22\n\2"+
		"\66@\7\u00e3\2\2\678\7\4\2\289\5\6\4\29:\7\5\2\2:@\3\2\2\2;<\t\2\2\2<"+
		"@\5\6\4\16=>\7\u00d7\2\2>@\5\6\4\r?\64\3\2\2\2?\66\3\2\2\2?\67\3\2\2\2"+
		"?;\3\2\2\2?=\3\2\2\2@t\3\2\2\2AB\f\17\2\2BC\7\n\2\2Cs\5\6\4\17DE\f\f\2"+
		"\2EF\7\u00d8\2\2Fs\5\6\4\rGH\f\13\2\2HI\7\u00d9\2\2Is\5\6\4\fJK\f\n\2"+
		"\2KL\t\3\2\2Ls\5\6\4\13MN\f\t\2\2NO\t\2\2\2Os\5\6\4\nPQ\f\b\2\2QR\t\4"+
		"\2\2Rs\5\6\4\tST\f\7\2\2TU\t\5\2\2Us\5\6\4\bVW\f\6\2\2WX\t\6\2\2Xs\5\6"+
		"\4\7YZ\f\4\2\2Z[\t\7\2\2[s\5\6\4\5\\]\f\3\2\2]^\7\u00e6\2\2^s\5\6\4\3"+
		"_`\f\22\2\2`b\7\4\2\2ac\5\b\5\2ba\3\2\2\2bc\3\2\2\2cd\3\2\2\2ds\7\5\2"+
		"\2ef\f\21\2\2fg\7\6\2\2gh\5\6\4\2hi\7\7\2\2is\3\2\2\2jk\f\20\2\2kl\7\b"+
		"\2\2lm\5\6\4\2mn\7\t\2\2ns\3\2\2\2op\f\5\2\2pq\t\b\2\2qs\5\16\b\2rA\3"+
		"\2\2\2rD\3\2\2\2rG\3\2\2\2rJ\3\2\2\2rM\3\2\2\2rP\3\2\2\2rS\3\2\2\2rV\3"+
		"\2\2\2rY\3\2\2\2r\\\3\2\2\2r_\3\2\2\2re\3\2\2\2rj\3\2\2\2ro\3\2\2\2sv"+
		"\3\2\2\2tr\3\2\2\2tu\3\2\2\2u\7\3\2\2\2vt\3\2\2\2wz\b\5\1\2x{\5\6\4\2"+
		"y{\5\n\6\2zx\3\2\2\2zy\3\2\2\2{\u0083\3\2\2\2|\177\7\u00e7\2\2}\u0080"+
		"\5\6\4\2~\u0080\5\n\6\2\177}\3\2\2\2\177~\3\2\2\2\u0080\u0082\3\2\2\2"+
		"\u0081|\3\2\2\2\u0082\u0085\3\2\2\2\u0083\u0081\3\2\2\2\u0083\u0084\3"+
		"\2\2\2\u0084\u008f\3\2\2\2\u0085\u0083\3\2\2\2\u0086\u0088\f\3\2\2\u0087"+
		"\u0089\7\u00e7\2\2\u0088\u0087\3\2\2\2\u0089\u008a\3\2\2\2\u008a\u0088"+
		"\3\2\2\2\u008a\u008b\3\2\2\2\u008b\u008c\3\2\2\2\u008c\u008e\5\b\5\4\u008d"+
		"\u0086\3\2\2\2\u008e\u0091\3\2\2\2\u008f\u008d\3\2\2\2\u008f\u0090\3\2"+
		"\2\2\u0090\t\3\2\2\2\u0091\u008f\3\2\2\2\u0092\u0093\7\22\2\2\u0093\u0094"+
		"\7\u00e3\2\2\u0094\u0095\7\f\2\2\u0095\u0096\7\u00e3\2\2\u0096\u00a0\3"+
		"\2\2\2\u0097\u0098\7\u00e7\2\2\u0098\u009a\7\22\2\2\u0099\u0097\3\2\2"+
		"\2\u0099\u009a\3\2\2\2\u009a\u009b\3\2\2\2\u009b\u009c\7\u00e3\2\2\u009c"+
		"\u009d\7\f\2\2\u009d\u009f\7\u00e3\2\2\u009e\u0099\3\2\2\2\u009f\u00a2"+
		"\3\2\2\2\u00a0\u009e\3\2\2\2\u00a0\u00a1\3\2\2\2\u00a1\u00b1\3\2\2\2\u00a2"+
		"\u00a0\3\2\2\2\u00a3\u00a4\7\22\2\2\u00a4\u00a8\7\u00e3\2\2\u00a5\u00a7"+
		"\7\u00e3\2\2\u00a6\u00a5\3\2\2\2\u00a7\u00aa\3\2\2\2\u00a8\u00a6\3\2\2"+
		"\2\u00a8\u00a9\3\2\2\2\u00a9\u00b1\3\2\2\2\u00aa\u00a8\3\2\2\2\u00ab\u00ac"+
		"\7\22\2\2\u00ac\u00ad\7\u00e3\2\2\u00ad\u00ae\7\b\2\2\u00ae\u00af\7\r"+
		"\2\2\u00af\u00b1\7\t\2\2\u00b0\u0092\3\2\2\2\u00b0\u00a3\3\2\2\2\u00b0"+
		"\u00ab\3\2\2\2\u00b1\13\3\2\2\2\u00b2\u00b7\7\u00e3\2\2\u00b3\u00b4\7"+
		"\u00e3\2\2\u00b4\u00b5\7\f\2\2\u00b5\u00b7\7\u00e3\2\2\u00b6\u00b2\3\2"+
		"\2\2\u00b6\u00b3\3\2\2\2\u00b7\u00b8\3\2\2\2\u00b8\u00b6\3\2\2\2\u00b8"+
		"\u00b9\3\2\2\2\u00b9\r\3\2\2\2\u00ba\u00cd\7\u00e3\2\2\u00bb\u00be\7\4"+
		"\2\2\u00bc\u00bf\5\22\n\2\u00bd\u00bf\5\20\t\2\u00be\u00bc\3\2\2\2\u00be"+
		"\u00bd\3\2\2\2\u00bf\u00c7\3\2\2\2\u00c0\u00c3\7\u00e7\2\2\u00c1\u00c4"+
		"\5\22\n\2\u00c2\u00c4\5\20\t\2\u00c3\u00c1\3\2\2\2\u00c3\u00c2\3\2\2\2"+
		"\u00c4\u00c6\3\2\2\2\u00c5\u00c0\3\2\2\2\u00c6\u00c9\3\2\2\2\u00c7\u00c5"+
		"\3\2\2\2\u00c7\u00c8\3\2\2\2\u00c8\u00ca\3\2\2\2\u00c9\u00c7\3\2\2\2\u00ca"+
		"\u00cb\7\5\2\2\u00cb\u00cd\3\2\2\2\u00cc\u00ba\3\2\2\2\u00cc\u00bb\3\2"+
		"\2\2\u00cd\17\3\2\2\2\u00ce\u00cf\7\u00e1\2\2\u00cf\u00d0\7\23\2\2\u00d0"+
		"\u00d1\7\u00e1\2\2\u00d1\21\3\2\2\2\u00d2\u00d3\t\t\2\2\u00d3\23\3\2\2"+
		"\2\u00d4\u00d5\b\13\1\2\u00d5\u00da\7\u00e3\2\2\u00d6\u00da\7\u00aa\2"+
		"\2\u00d7\u00da\7\u0092\2\2\u00d8\u00da\7\u00af\2\2\u00d9\u00d4\3\2\2\2"+
		"\u00d9\u00d6\3\2\2\2\u00d9\u00d7\3\2\2\2\u00d9\u00d8\3\2\2\2\u00da\u00e0"+
		"\3\2\2\2\u00db\u00dc\f\7\2\2\u00dc\u00dd\7\u00e4\2\2\u00dd\u00df\5\24"+
		"\13\b\u00de\u00db\3\2\2\2\u00df\u00e2\3\2\2\2\u00e0\u00de\3\2\2\2\u00e0"+
		"\u00e1\3\2\2\2\u00e1\25\3\2\2\2\u00e2\u00e0\3\2\2\2\31\31\62?brtz\177"+
		"\u0083\u008a\u008f\u0099\u00a0\u00a8\u00b0\u00b6\u00b8\u00be\u00c3\u00c7"+
		"\u00cc\u00d9\u00e0";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}