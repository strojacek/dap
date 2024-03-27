// Generated from GLMProc.g4 by ANTLR 4.8
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class GLMProcParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, T__16=17, 
		CLASS=18, MODEL=19, FREQ=20, ID=21, WEIGHT=22, ABEND=23, END=24, LENGTH=25, 
		QKUPCASE=26, SYSEVALF=27, ABORT=28, EVAL=29, LET=30, QSCAN=31, SYSEXEC=32, 
		ACT=33, FILE=34, LIST=35, QSUBSTR=36, SYSFUNC=37, ACTIVATE=38, GLOBAL=39, 
		LISTM=40, QSYSFUNC=41, SYSGET=42, BQUOTE=43, GO=44, LOCAL=45, QUOTE=46, 
		SYSRPUT=47, BY=48, GOTO=49, MACRO=50, QUPCASE=51, THEN=52, CLEAR=53, IF=54, 
		MEND=55, RESOLVE=56, TO=57, CLOSE=58, INC=59, PAUSE=60, RETURN=61, TSO=62, 
		CMS=63, INCLUDE=64, NRSTR=65, RUN=66, UNQUOTE=67, COMANDR=68, INDEX=69, 
		ON=70, SAVE=71, UNSTR=72, COPY=73, INFILE=74, OPEN=75, SCAN=76, UNTIL=77, 
		DEACT=78, INPUT=79, PUT=80, STOP=81, UPCASE=82, DEL=83, KCMPRES=84, NRBQUOTE=85, 
		STR=86, WHILE=87, DELETE=88, KINDEX=89, NRQUOTE=90, SYSCALL=91, WINDOW=92, 
		DISPLAY=93, KLEFT=94, METASYM=95, SUBSTR=96, DMIDSPLY=97, KLENGTH=98, 
		QKCMPRES=99, SUPERQ=100, DMISPLIT=101, KSCAN=102, QKLEFT=103, SYMDEL=104, 
		DO=105, KSUBSTR=106, QKSCAN=107, SYMEXIST=108, EDIT=109, KTRIM=110, QKSUBSTR=111, 
		SYMGLOBL=112, ELSE=113, KUPCASE=114, QKTRIM=115, SYMLOCAL=116, Tk_NULL=117, 
		CANCEL=118, NOLIST=119, ARRAY=120, ARRAY_NUMERIC_ELEMENTS=121, ARRAY_CHARACTER_ELEMENTS=122, 
		ARRAY_ALL_ELEMENTS=123, GROUPFORMAT=124, NOTSORTED=125, DESCENDING=126, 
		CALL=127, DEBUG=128, NESTING=129, STACK=130, READ=131, PW=132, SOURCE=133, 
		VIEW=134, PGM=135, ENCRYPT=136, NOSAVE=137, DATALINES=138, CARDS=139, 
		LINES=140, DATALINES4=141, CARDS4=142, LINES4=143, END_DATALINES4=144, 
		ALTER=145, DISK=146, DUMMY=147, GTERM=148, PIPE=149, PLOTTER=150, PRINTER=151, 
		TAPE=152, TEMP=153, TERMINAL=154, UPRINTER=155, DSD=156, EXPANDTABS=157, 
		NOEXPANDTABS=158, FLOWOVER=159, MISSOVER=160, PAD=161, NOPAD=162, SCANOVER=163, 
		SHAREBUFFERS=164, STOPOVER=165, TRUNCOVER=166, V_INFILE_=167, INPUT_ODS=168, 
		DATE=169, DATETIME=170, DDMMYY=171, INFORMAT_COMMA=172, INFORMAT_CHAR=173, 
		DROP=174, PROC=175, ANOVA=176, MEANS=177, REG=178, CORR=179, SGPLOT=180, 
		PRINT=181, DATA=182, GLM=183, SQL=184, UNIVARIATE=185, NPAR1WAY=186, IMPORT=187, 
		SORT=188, DATASETS=189, TABULATE=190, RANK=191, CHART=192, LOGISTIC=193, 
		SURVEYSELECT=194, Informat=195, DOLLAR=196, EQ=197, NE=198, GT=199, LT=200, 
		GE=201, LE=202, IN=203, EQC=204, NEC=205, GTC=206, LTC=207, GEC=208, LEC=209, 
		INColon=210, AND=211, OR=212, NOT=213, MIN=214, MAX=215, DateLiteral=216, 
		TimeLiteral=217, DateTimeLiteral=218, BitLiteral=219, NameLiteral=220, 
		HexLiteral=221, STRINGLITERAL=222, INT=223, FloatingPointLiteral=224, 
		Identifier=225, DOT=226, AT=227, EQUAL=228, COMMA=229, LBracket=230, RBracket=231, 
		WS=232, COMMENT=233, LINE_COMMENT=234;
	public static final int
		RULE_glm_main = 0, RULE_glm_proc = 1, RULE_expression = 2, RULE_expressionList = 3, 
		RULE_of_var_list = 4, RULE_identifiers_list = 5, RULE_in_var_list = 6, 
		RULE_colonInts = 7, RULE_literal = 8, RULE_variables = 9;
	private static String[] makeRuleNames() {
		return new String[] {
			"glm_main", "glm_proc", "expression", "expressionList", "of_var_list", 
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
			null, null, null, null, "';;;;'", null, null, null, null, null, null, 
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
			null, null, null, null, null, null, "CLASS", "MODEL", "FREQ", "ID", "WEIGHT", 
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
			"MEANS", "REG", "CORR", "SGPLOT", "PRINT", "DATA", "GLM", "SQL", "UNIVARIATE", 
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
	public String getGrammarFileName() { return "GLMProc.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public GLMProcParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class Glm_mainContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(GLMProcParser.EOF, 0); }
		public List<Glm_procContext> glm_proc() {
			return getRuleContexts(Glm_procContext.class);
		}
		public Glm_procContext glm_proc(int i) {
			return getRuleContext(Glm_procContext.class,i);
		}
		public Glm_mainContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_glm_main; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof GLMProcListener ) ((GLMProcListener)listener).enterGlm_main(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof GLMProcListener ) ((GLMProcListener)listener).exitGlm_main(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof GLMProcVisitor ) return ((GLMProcVisitor<? extends T>)visitor).visitGlm_main(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Glm_mainContext glm_main() throws RecognitionException {
		Glm_mainContext _localctx = new Glm_mainContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_glm_main);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(23);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << CLASS) | (1L << MODEL) | (1L << FREQ) | (1L << ID) | (1L << WEIGHT) | (1L << BY))) != 0)) {
				{
				{
				setState(20);
				glm_proc();
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

	public static class Glm_procContext extends ParserRuleContext {
		public TerminalNode CLASS() { return getToken(GLMProcParser.CLASS, 0); }
		public VariablesContext variables() {
			return getRuleContext(VariablesContext.class,0);
		}
		public TerminalNode MODEL() { return getToken(GLMProcParser.MODEL, 0); }
		public TerminalNode BY() { return getToken(GLMProcParser.BY, 0); }
		public TerminalNode FREQ() { return getToken(GLMProcParser.FREQ, 0); }
		public TerminalNode ID() { return getToken(GLMProcParser.ID, 0); }
		public TerminalNode WEIGHT() { return getToken(GLMProcParser.WEIGHT, 0); }
		public Glm_procContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_glm_proc; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof GLMProcListener ) ((GLMProcListener)listener).enterGlm_proc(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof GLMProcListener ) ((GLMProcListener)listener).exitGlm_proc(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof GLMProcVisitor ) return ((GLMProcVisitor<? extends T>)visitor).visitGlm_proc(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Glm_procContext glm_proc() throws RecognitionException {
		Glm_procContext _localctx = new Glm_procContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_glm_proc);
		try {
			setState(52);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case CLASS:
				enterOuterAlt(_localctx, 1);
				{
				setState(28);
				match(CLASS);
				setState(29);
				variables(0);
				setState(30);
				match(T__0);
				}
				break;
			case MODEL:
				enterOuterAlt(_localctx, 2);
				{
				setState(32);
				match(MODEL);
				setState(33);
				variables(0);
				setState(34);
				match(T__0);
				}
				break;
			case BY:
				enterOuterAlt(_localctx, 3);
				{
				setState(36);
				match(BY);
				setState(37);
				variables(0);
				setState(38);
				match(T__0);
				}
				break;
			case FREQ:
				enterOuterAlt(_localctx, 4);
				{
				setState(40);
				match(FREQ);
				setState(41);
				variables(0);
				setState(42);
				match(T__0);
				}
				break;
			case ID:
				enterOuterAlt(_localctx, 5);
				{
				setState(44);
				match(ID);
				setState(45);
				variables(0);
				setState(46);
				match(T__0);
				}
				break;
			case WEIGHT:
				enterOuterAlt(_localctx, 6);
				{
				setState(48);
				match(WEIGHT);
				setState(49);
				variables(0);
				setState(50);
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
		public TerminalNode Identifier() { return getToken(GLMProcParser.Identifier, 0); }
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode NOT() { return getToken(GLMProcParser.NOT, 0); }
		public TerminalNode MIN() { return getToken(GLMProcParser.MIN, 0); }
		public TerminalNode MAX() { return getToken(GLMProcParser.MAX, 0); }
		public TerminalNode EQ() { return getToken(GLMProcParser.EQ, 0); }
		public TerminalNode NE() { return getToken(GLMProcParser.NE, 0); }
		public TerminalNode GT() { return getToken(GLMProcParser.GT, 0); }
		public TerminalNode LT() { return getToken(GLMProcParser.LT, 0); }
		public TerminalNode GE() { return getToken(GLMProcParser.GE, 0); }
		public TerminalNode LE() { return getToken(GLMProcParser.LE, 0); }
		public TerminalNode EQC() { return getToken(GLMProcParser.EQC, 0); }
		public TerminalNode NEC() { return getToken(GLMProcParser.NEC, 0); }
		public TerminalNode GTC() { return getToken(GLMProcParser.GTC, 0); }
		public TerminalNode LTC() { return getToken(GLMProcParser.LTC, 0); }
		public TerminalNode GEC() { return getToken(GLMProcParser.GEC, 0); }
		public TerminalNode LEC() { return getToken(GLMProcParser.LEC, 0); }
		public TerminalNode AND() { return getToken(GLMProcParser.AND, 0); }
		public TerminalNode OR() { return getToken(GLMProcParser.OR, 0); }
		public TerminalNode EQUAL() { return getToken(GLMProcParser.EQUAL, 0); }
		public ExpressionListContext expressionList() {
			return getRuleContext(ExpressionListContext.class,0);
		}
		public In_var_listContext in_var_list() {
			return getRuleContext(In_var_listContext.class,0);
		}
		public TerminalNode IN() { return getToken(GLMProcParser.IN, 0); }
		public TerminalNode INColon() { return getToken(GLMProcParser.INColon, 0); }
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof GLMProcListener ) ((GLMProcListener)listener).enterExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof GLMProcListener ) ((GLMProcListener)listener).exitExpression(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof GLMProcVisitor ) return ((GLMProcVisitor<? extends T>)visitor).visitExpression(this);
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
			setState(65);
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
				setState(55);
				literal();
				}
				break;
			case Identifier:
				{
				setState(56);
				match(Identifier);
				}
				break;
			case T__1:
				{
				setState(57);
				match(T__1);
				setState(58);
				expression(0);
				setState(59);
				match(T__2);
				}
				break;
			case T__8:
			case T__9:
				{
				setState(61);
				_la = _input.LA(1);
				if ( !(_la==T__8 || _la==T__9) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(62);
				expression(12);
				}
				break;
			case NOT:
				{
				setState(63);
				match(NOT);
				setState(64);
				expression(11);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(118);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,5,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(116);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
					case 1:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(67);
						if (!(precpred(_ctx, 13))) throw new FailedPredicateException(this, "precpred(_ctx, 13)");
						setState(68);
						match(T__7);
						setState(69);
						expression(13);
						}
						break;
					case 2:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(70);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(71);
						match(MIN);
						setState(72);
						expression(11);
						}
						break;
					case 3:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(73);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(74);
						match(MAX);
						setState(75);
						expression(10);
						}
						break;
					case 4:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(76);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(77);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__10) | (1L << T__11) | (1L << T__12))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(78);
						expression(9);
						}
						break;
					case 5:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(79);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(80);
						_la = _input.LA(1);
						if ( !(_la==T__8 || _la==T__9) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(81);
						expression(8);
						}
						break;
					case 6:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(82);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(83);
						_la = _input.LA(1);
						if ( !(_la==T__13 || _la==T__14) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(84);
						expression(7);
						}
						break;
					case 7:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(85);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(86);
						_la = _input.LA(1);
						if ( !(((((_la - 197)) & ~0x3f) == 0 && ((1L << (_la - 197)) & ((1L << (EQ - 197)) | (1L << (NE - 197)) | (1L << (GT - 197)) | (1L << (LT - 197)) | (1L << (GE - 197)) | (1L << (LE - 197)))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(87);
						expression(6);
						}
						break;
					case 8:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(88);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(89);
						_la = _input.LA(1);
						if ( !(((((_la - 204)) & ~0x3f) == 0 && ((1L << (_la - 204)) & ((1L << (EQC - 204)) | (1L << (NEC - 204)) | (1L << (GTC - 204)) | (1L << (LTC - 204)) | (1L << (GEC - 204)) | (1L << (LEC - 204)))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(90);
						expression(5);
						}
						break;
					case 9:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(91);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(92);
						_la = _input.LA(1);
						if ( !(_la==AND || _la==OR) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(93);
						expression(3);
						}
						break;
					case 10:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(94);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(95);
						match(EQUAL);
						setState(96);
						expression(1);
						}
						break;
					case 11:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(97);
						if (!(precpred(_ctx, 16))) throw new FailedPredicateException(this, "precpred(_ctx, 16)");
						setState(98);
						match(T__1);
						setState(100);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__1) | (1L << T__8) | (1L << T__9) | (1L << T__15))) != 0) || ((((_la - 213)) & ~0x3f) == 0 && ((1L << (_la - 213)) & ((1L << (NOT - 213)) | (1L << (DateLiteral - 213)) | (1L << (TimeLiteral - 213)) | (1L << (DateTimeLiteral - 213)) | (1L << (BitLiteral - 213)) | (1L << (NameLiteral - 213)) | (1L << (HexLiteral - 213)) | (1L << (STRINGLITERAL - 213)) | (1L << (INT - 213)) | (1L << (FloatingPointLiteral - 213)) | (1L << (Identifier - 213)) | (1L << (DOT - 213)))) != 0)) {
							{
							setState(99);
							expressionList(0);
							}
						}

						setState(102);
						match(T__2);
						}
						break;
					case 12:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(103);
						if (!(precpred(_ctx, 15))) throw new FailedPredicateException(this, "precpred(_ctx, 15)");
						setState(104);
						match(T__3);
						setState(105);
						expression(0);
						setState(106);
						match(T__4);
						}
						break;
					case 13:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(108);
						if (!(precpred(_ctx, 14))) throw new FailedPredicateException(this, "precpred(_ctx, 14)");
						setState(109);
						match(T__5);
						setState(110);
						expression(0);
						setState(111);
						match(T__6);
						}
						break;
					case 14:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(113);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(114);
						_la = _input.LA(1);
						if ( !(_la==IN || _la==INColon) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(115);
						in_var_list();
						}
						break;
					}
					} 
				}
				setState(120);
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
		public List<TerminalNode> COMMA() { return getTokens(GLMProcParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(GLMProcParser.COMMA, i);
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
			if ( listener instanceof GLMProcListener ) ((GLMProcListener)listener).enterExpressionList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof GLMProcListener ) ((GLMProcListener)listener).exitExpressionList(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof GLMProcVisitor ) return ((GLMProcVisitor<? extends T>)visitor).visitExpressionList(this);
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
			setState(124);
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
				setState(122);
				expression(0);
				}
				break;
			case T__15:
				{
				setState(123);
				of_var_list();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(133);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(126);
					match(COMMA);
					setState(129);
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
						setState(127);
						expression(0);
						}
						break;
					case T__15:
						{
						setState(128);
						of_var_list();
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					}
					} 
				}
				setState(135);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
			}
			}
			_ctx.stop = _input.LT(-1);
			setState(145);
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
					setState(136);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(138); 
					_errHandler.sync(this);
					_la = _input.LA(1);
					do {
						{
						{
						setState(137);
						match(COMMA);
						}
						}
						setState(140); 
						_errHandler.sync(this);
						_la = _input.LA(1);
					} while ( _la==COMMA );
					setState(142);
					expressionList(2);
					}
					} 
				}
				setState(147);
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
		public List<TerminalNode> Identifier() { return getTokens(GLMProcParser.Identifier); }
		public TerminalNode Identifier(int i) {
			return getToken(GLMProcParser.Identifier, i);
		}
		public List<TerminalNode> COMMA() { return getTokens(GLMProcParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(GLMProcParser.COMMA, i);
		}
		public Of_var_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_of_var_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof GLMProcListener ) ((GLMProcListener)listener).enterOf_var_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof GLMProcListener ) ((GLMProcListener)listener).exitOf_var_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof GLMProcVisitor ) return ((GLMProcVisitor<? extends T>)visitor).visitOf_var_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Of_var_listContext of_var_list() throws RecognitionException {
		Of_var_listContext _localctx = new Of_var_listContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_of_var_list);
		int _la;
		try {
			int _alt;
			setState(178);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(148);
				match(T__15);
				{
				setState(149);
				match(Identifier);
				setState(150);
				match(T__9);
				setState(151);
				match(Identifier);
				}
				setState(162);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(155);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if (_la==COMMA) {
							{
							setState(153);
							match(COMMA);
							setState(154);
							match(T__15);
							}
						}

						{
						setState(157);
						match(Identifier);
						setState(158);
						match(T__9);
						setState(159);
						match(Identifier);
						}
						}
						} 
					}
					setState(164);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(165);
				match(T__15);
				setState(166);
				match(Identifier);
				setState(170);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(167);
						match(Identifier);
						}
						} 
					}
					setState(172);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(173);
				match(T__15);
				setState(174);
				match(Identifier);
				setState(175);
				match(T__5);
				setState(176);
				match(T__10);
				setState(177);
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
		public List<TerminalNode> Identifier() { return getTokens(GLMProcParser.Identifier); }
		public TerminalNode Identifier(int i) {
			return getToken(GLMProcParser.Identifier, i);
		}
		public Identifiers_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_identifiers_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof GLMProcListener ) ((GLMProcListener)listener).enterIdentifiers_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof GLMProcListener ) ((GLMProcListener)listener).exitIdentifiers_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof GLMProcVisitor ) return ((GLMProcVisitor<? extends T>)visitor).visitIdentifiers_list(this);
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
			setState(184); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				setState(184);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
				case 1:
					{
					setState(180);
					match(Identifier);
					}
					break;
				case 2:
					{
					setState(181);
					match(Identifier);
					setState(182);
					match(T__9);
					setState(183);
					match(Identifier);
					}
					break;
				}
				}
				setState(186); 
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
		public TerminalNode Identifier() { return getToken(GLMProcParser.Identifier, 0); }
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
		public List<TerminalNode> COMMA() { return getTokens(GLMProcParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(GLMProcParser.COMMA, i);
		}
		public In_var_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_in_var_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof GLMProcListener ) ((GLMProcListener)listener).enterIn_var_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof GLMProcListener ) ((GLMProcListener)listener).exitIn_var_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof GLMProcVisitor ) return ((GLMProcVisitor<? extends T>)visitor).visitIn_var_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final In_var_listContext in_var_list() throws RecognitionException {
		In_var_listContext _localctx = new In_var_listContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_in_var_list);
		int _la;
		try {
			setState(206);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Identifier:
				enterOuterAlt(_localctx, 1);
				{
				setState(188);
				match(Identifier);
				}
				break;
			case T__1:
				enterOuterAlt(_localctx, 2);
				{
				setState(189);
				match(T__1);
				setState(192);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
				case 1:
					{
					setState(190);
					literal();
					}
					break;
				case 2:
					{
					setState(191);
					colonInts();
					}
					break;
				}
				setState(201);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMMA) {
					{
					{
					setState(194);
					match(COMMA);
					setState(197);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
					case 1:
						{
						setState(195);
						literal();
						}
						break;
					case 2:
						{
						setState(196);
						colonInts();
						}
						break;
					}
					}
					}
					setState(203);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(204);
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
		public List<TerminalNode> INT() { return getTokens(GLMProcParser.INT); }
		public TerminalNode INT(int i) {
			return getToken(GLMProcParser.INT, i);
		}
		public ColonIntsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_colonInts; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof GLMProcListener ) ((GLMProcListener)listener).enterColonInts(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof GLMProcListener ) ((GLMProcListener)listener).exitColonInts(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof GLMProcVisitor ) return ((GLMProcVisitor<? extends T>)visitor).visitColonInts(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ColonIntsContext colonInts() throws RecognitionException {
		ColonIntsContext _localctx = new ColonIntsContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_colonInts);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(208);
			match(INT);
			setState(209);
			match(T__16);
			setState(210);
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
		public TerminalNode INT() { return getToken(GLMProcParser.INT, 0); }
		public TerminalNode FloatingPointLiteral() { return getToken(GLMProcParser.FloatingPointLiteral, 0); }
		public TerminalNode STRINGLITERAL() { return getToken(GLMProcParser.STRINGLITERAL, 0); }
		public TerminalNode DateLiteral() { return getToken(GLMProcParser.DateLiteral, 0); }
		public TerminalNode TimeLiteral() { return getToken(GLMProcParser.TimeLiteral, 0); }
		public TerminalNode DateTimeLiteral() { return getToken(GLMProcParser.DateTimeLiteral, 0); }
		public TerminalNode BitLiteral() { return getToken(GLMProcParser.BitLiteral, 0); }
		public TerminalNode NameLiteral() { return getToken(GLMProcParser.NameLiteral, 0); }
		public TerminalNode HexLiteral() { return getToken(GLMProcParser.HexLiteral, 0); }
		public TerminalNode DOT() { return getToken(GLMProcParser.DOT, 0); }
		public LiteralContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_literal; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof GLMProcListener ) ((GLMProcListener)listener).enterLiteral(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof GLMProcListener ) ((GLMProcListener)listener).exitLiteral(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof GLMProcVisitor ) return ((GLMProcVisitor<? extends T>)visitor).visitLiteral(this);
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
			setState(212);
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
		public TerminalNode Identifier() { return getToken(GLMProcParser.Identifier, 0); }
		public TerminalNode DATE() { return getToken(GLMProcParser.DATE, 0); }
		public TerminalNode ALTER() { return getToken(GLMProcParser.ALTER, 0); }
		public TerminalNode DROP() { return getToken(GLMProcParser.DROP, 0); }
		public List<VariablesContext> variables() {
			return getRuleContexts(VariablesContext.class);
		}
		public VariablesContext variables(int i) {
			return getRuleContext(VariablesContext.class,i);
		}
		public TerminalNode DOT() { return getToken(GLMProcParser.DOT, 0); }
		public VariablesContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variables; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof GLMProcListener ) ((GLMProcListener)listener).enterVariables(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof GLMProcListener ) ((GLMProcListener)listener).exitVariables(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof GLMProcVisitor ) return ((GLMProcVisitor<? extends T>)visitor).visitVariables(this);
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
			setState(219);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Identifier:
				{
				setState(215);
				match(Identifier);
				}
				break;
			case DATE:
				{
				setState(216);
				match(DATE);
				}
				break;
			case ALTER:
				{
				setState(217);
				match(ALTER);
				}
				break;
			case DROP:
				{
				setState(218);
				match(DROP);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(226);
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
					setState(221);
					if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
					setState(222);
					match(DOT);
					setState(223);
					variables(6);
					}
					} 
				}
				setState(228);
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\u00ec\u00e8\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\3\2\7\2\30\n\2\f\2\16\2\33\13\2\3\2\3\2\3\3\3\3\3\3\3\3\3\3\3\3"+
		"\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3"+
		"\3\5\3\67\n\3\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\5\4D\n\4\3\4"+
		"\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3"+
		"\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\5\4g\n\4\3"+
		"\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\7\4w\n\4\f\4\16"+
		"\4z\13\4\3\5\3\5\3\5\5\5\177\n\5\3\5\3\5\3\5\5\5\u0084\n\5\7\5\u0086\n"+
		"\5\f\5\16\5\u0089\13\5\3\5\3\5\6\5\u008d\n\5\r\5\16\5\u008e\3\5\7\5\u0092"+
		"\n\5\f\5\16\5\u0095\13\5\3\6\3\6\3\6\3\6\3\6\3\6\3\6\5\6\u009e\n\6\3\6"+
		"\3\6\3\6\7\6\u00a3\n\6\f\6\16\6\u00a6\13\6\3\6\3\6\3\6\7\6\u00ab\n\6\f"+
		"\6\16\6\u00ae\13\6\3\6\3\6\3\6\3\6\3\6\5\6\u00b5\n\6\3\7\3\7\3\7\3\7\6"+
		"\7\u00bb\n\7\r\7\16\7\u00bc\3\b\3\b\3\b\3\b\5\b\u00c3\n\b\3\b\3\b\3\b"+
		"\5\b\u00c8\n\b\7\b\u00ca\n\b\f\b\16\b\u00cd\13\b\3\b\3\b\5\b\u00d1\n\b"+
		"\3\t\3\t\3\t\3\t\3\n\3\n\3\13\3\13\3\13\3\13\3\13\5\13\u00de\n\13\3\13"+
		"\3\13\3\13\7\13\u00e3\n\13\f\13\16\13\u00e6\13\13\3\13\2\5\6\b\24\f\2"+
		"\4\6\b\n\f\16\20\22\24\2\n\3\2\13\f\3\2\r\17\3\2\20\21\3\2\u00c7\u00cc"+
		"\3\2\u00ce\u00d3\3\2\u00d5\u00d6\4\2\u00cd\u00cd\u00d4\u00d4\4\2\u00da"+
		"\u00e2\u00e4\u00e4\2\u010a\2\31\3\2\2\2\4\66\3\2\2\2\6C\3\2\2\2\b{\3\2"+
		"\2\2\n\u00b4\3\2\2\2\f\u00ba\3\2\2\2\16\u00d0\3\2\2\2\20\u00d2\3\2\2\2"+
		"\22\u00d6\3\2\2\2\24\u00dd\3\2\2\2\26\30\5\4\3\2\27\26\3\2\2\2\30\33\3"+
		"\2\2\2\31\27\3\2\2\2\31\32\3\2\2\2\32\34\3\2\2\2\33\31\3\2\2\2\34\35\7"+
		"\2\2\3\35\3\3\2\2\2\36\37\7\24\2\2\37 \5\24\13\2 !\7\3\2\2!\67\3\2\2\2"+
		"\"#\7\25\2\2#$\5\24\13\2$%\7\3\2\2%\67\3\2\2\2&\'\7\62\2\2\'(\5\24\13"+
		"\2()\7\3\2\2)\67\3\2\2\2*+\7\26\2\2+,\5\24\13\2,-\7\3\2\2-\67\3\2\2\2"+
		"./\7\27\2\2/\60\5\24\13\2\60\61\7\3\2\2\61\67\3\2\2\2\62\63\7\30\2\2\63"+
		"\64\5\24\13\2\64\65\7\3\2\2\65\67\3\2\2\2\66\36\3\2\2\2\66\"\3\2\2\2\66"+
		"&\3\2\2\2\66*\3\2\2\2\66.\3\2\2\2\66\62\3\2\2\2\67\5\3\2\2\289\b\4\1\2"+
		"9D\5\22\n\2:D\7\u00e3\2\2;<\7\4\2\2<=\5\6\4\2=>\7\5\2\2>D\3\2\2\2?@\t"+
		"\2\2\2@D\5\6\4\16AB\7\u00d7\2\2BD\5\6\4\rC8\3\2\2\2C:\3\2\2\2C;\3\2\2"+
		"\2C?\3\2\2\2CA\3\2\2\2Dx\3\2\2\2EF\f\17\2\2FG\7\n\2\2Gw\5\6\4\17HI\f\f"+
		"\2\2IJ\7\u00d8\2\2Jw\5\6\4\rKL\f\13\2\2LM\7\u00d9\2\2Mw\5\6\4\fNO\f\n"+
		"\2\2OP\t\3\2\2Pw\5\6\4\13QR\f\t\2\2RS\t\2\2\2Sw\5\6\4\nTU\f\b\2\2UV\t"+
		"\4\2\2Vw\5\6\4\tWX\f\7\2\2XY\t\5\2\2Yw\5\6\4\bZ[\f\6\2\2[\\\t\6\2\2\\"+
		"w\5\6\4\7]^\f\4\2\2^_\t\7\2\2_w\5\6\4\5`a\f\3\2\2ab\7\u00e6\2\2bw\5\6"+
		"\4\3cd\f\22\2\2df\7\4\2\2eg\5\b\5\2fe\3\2\2\2fg\3\2\2\2gh\3\2\2\2hw\7"+
		"\5\2\2ij\f\21\2\2jk\7\6\2\2kl\5\6\4\2lm\7\7\2\2mw\3\2\2\2no\f\20\2\2o"+
		"p\7\b\2\2pq\5\6\4\2qr\7\t\2\2rw\3\2\2\2st\f\5\2\2tu\t\b\2\2uw\5\16\b\2"+
		"vE\3\2\2\2vH\3\2\2\2vK\3\2\2\2vN\3\2\2\2vQ\3\2\2\2vT\3\2\2\2vW\3\2\2\2"+
		"vZ\3\2\2\2v]\3\2\2\2v`\3\2\2\2vc\3\2\2\2vi\3\2\2\2vn\3\2\2\2vs\3\2\2\2"+
		"wz\3\2\2\2xv\3\2\2\2xy\3\2\2\2y\7\3\2\2\2zx\3\2\2\2{~\b\5\1\2|\177\5\6"+
		"\4\2}\177\5\n\6\2~|\3\2\2\2~}\3\2\2\2\177\u0087\3\2\2\2\u0080\u0083\7"+
		"\u00e7\2\2\u0081\u0084\5\6\4\2\u0082\u0084\5\n\6\2\u0083\u0081\3\2\2\2"+
		"\u0083\u0082\3\2\2\2\u0084\u0086\3\2\2\2\u0085\u0080\3\2\2\2\u0086\u0089"+
		"\3\2\2\2\u0087\u0085\3\2\2\2\u0087\u0088\3\2\2\2\u0088\u0093\3\2\2\2\u0089"+
		"\u0087\3\2\2\2\u008a\u008c\f\3\2\2\u008b\u008d\7\u00e7\2\2\u008c\u008b"+
		"\3\2\2\2\u008d\u008e\3\2\2\2\u008e\u008c\3\2\2\2\u008e\u008f\3\2\2\2\u008f"+
		"\u0090\3\2\2\2\u0090\u0092\5\b\5\4\u0091\u008a\3\2\2\2\u0092\u0095\3\2"+
		"\2\2\u0093\u0091\3\2\2\2\u0093\u0094\3\2\2\2\u0094\t\3\2\2\2\u0095\u0093"+
		"\3\2\2\2\u0096\u0097\7\22\2\2\u0097\u0098\7\u00e3\2\2\u0098\u0099\7\f"+
		"\2\2\u0099\u009a\7\u00e3\2\2\u009a\u00a4\3\2\2\2\u009b\u009c\7\u00e7\2"+
		"\2\u009c\u009e\7\22\2\2\u009d\u009b\3\2\2\2\u009d\u009e\3\2\2\2\u009e"+
		"\u009f\3\2\2\2\u009f\u00a0\7\u00e3\2\2\u00a0\u00a1\7\f\2\2\u00a1\u00a3"+
		"\7\u00e3\2\2\u00a2\u009d\3\2\2\2\u00a3\u00a6\3\2\2\2\u00a4\u00a2\3\2\2"+
		"\2\u00a4\u00a5\3\2\2\2\u00a5\u00b5\3\2\2\2\u00a6\u00a4\3\2\2\2\u00a7\u00a8"+
		"\7\22\2\2\u00a8\u00ac\7\u00e3\2\2\u00a9\u00ab\7\u00e3\2\2\u00aa\u00a9"+
		"\3\2\2\2\u00ab\u00ae\3\2\2\2\u00ac\u00aa\3\2\2\2\u00ac\u00ad\3\2\2\2\u00ad"+
		"\u00b5\3\2\2\2\u00ae\u00ac\3\2\2\2\u00af\u00b0\7\22\2\2\u00b0\u00b1\7"+
		"\u00e3\2\2\u00b1\u00b2\7\b\2\2\u00b2\u00b3\7\r\2\2\u00b3\u00b5\7\t\2\2"+
		"\u00b4\u0096\3\2\2\2\u00b4\u00a7\3\2\2\2\u00b4\u00af\3\2\2\2\u00b5\13"+
		"\3\2\2\2\u00b6\u00bb\7\u00e3\2\2\u00b7\u00b8\7\u00e3\2\2\u00b8\u00b9\7"+
		"\f\2\2\u00b9\u00bb\7\u00e3\2\2\u00ba\u00b6\3\2\2\2\u00ba\u00b7\3\2\2\2"+
		"\u00bb\u00bc\3\2\2\2\u00bc\u00ba\3\2\2\2\u00bc\u00bd\3\2\2\2\u00bd\r\3"+
		"\2\2\2\u00be\u00d1\7\u00e3\2\2\u00bf\u00c2\7\4\2\2\u00c0\u00c3\5\22\n"+
		"\2\u00c1\u00c3\5\20\t\2\u00c2\u00c0\3\2\2\2\u00c2\u00c1\3\2\2\2\u00c3"+
		"\u00cb\3\2\2\2\u00c4\u00c7\7\u00e7\2\2\u00c5\u00c8\5\22\n\2\u00c6\u00c8"+
		"\5\20\t\2\u00c7\u00c5\3\2\2\2\u00c7\u00c6\3\2\2\2\u00c8\u00ca\3\2\2\2"+
		"\u00c9\u00c4\3\2\2\2\u00ca\u00cd\3\2\2\2\u00cb\u00c9\3\2\2\2\u00cb\u00cc"+
		"\3\2\2\2\u00cc\u00ce\3\2\2\2\u00cd\u00cb\3\2\2\2\u00ce\u00cf\7\5\2\2\u00cf"+
		"\u00d1\3\2\2\2\u00d0\u00be\3\2\2\2\u00d0\u00bf\3\2\2\2\u00d1\17\3\2\2"+
		"\2\u00d2\u00d3\7\u00e1\2\2\u00d3\u00d4\7\23\2\2\u00d4\u00d5\7\u00e1\2"+
		"\2\u00d5\21\3\2\2\2\u00d6\u00d7\t\t\2\2\u00d7\23\3\2\2\2\u00d8\u00d9\b"+
		"\13\1\2\u00d9\u00de\7\u00e3\2\2\u00da\u00de\7\u00ab\2\2\u00db\u00de\7"+
		"\u0093\2\2\u00dc\u00de\7\u00b0\2\2\u00dd\u00d8\3\2\2\2\u00dd\u00da\3\2"+
		"\2\2\u00dd\u00db\3\2\2\2\u00dd\u00dc\3\2\2\2\u00de\u00e4\3\2\2\2\u00df"+
		"\u00e0\f\7\2\2\u00e0\u00e1\7\u00e4\2\2\u00e1\u00e3\5\24\13\b\u00e2\u00df"+
		"\3\2\2\2\u00e3\u00e6\3\2\2\2\u00e4\u00e2\3\2\2\2\u00e4\u00e5\3\2\2\2\u00e5"+
		"\25\3\2\2\2\u00e6\u00e4\3\2\2\2\31\31\66Cfvx~\u0083\u0087\u008e\u0093"+
		"\u009d\u00a4\u00ac\u00b4\u00ba\u00bc\u00c2\u00c7\u00cb\u00d0\u00dd\u00e4";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}