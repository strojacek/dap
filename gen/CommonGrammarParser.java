// Generated from /Users/sethtrojacek/IdeaProjects/jazz/src/main/antlr4/CommonGrammar.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class CommonGrammarParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, ABEND=17, 
		END=18, LENGTH=19, QKUPCASE=20, SYSEVALF=21, ABORT=22, EVAL=23, LET=24, 
		QSCAN=25, SYSEXEC=26, ACT=27, FILE=28, LIST=29, QSUBSTR=30, SYSFUNC=31, 
		ACTIVATE=32, GLOBAL=33, LISTM=34, QSYSFUNC=35, SYSGET=36, BQUOTE=37, GO=38, 
		LOCAL=39, QUOTE=40, SYSRPUT=41, BY=42, GOTO=43, MACRO=44, QUPCASE=45, 
		THEN=46, CLEAR=47, IF=48, MEND=49, RESOLVE=50, TO=51, CLOSE=52, INC=53, 
		PAUSE=54, RETURN=55, TSO=56, CMS=57, INCLUDE=58, NRSTR=59, RUN=60, UNQUOTE=61, 
		COMANDR=62, INDEX=63, ON=64, SAVE=65, UNSTR=66, COPY=67, INFILE=68, OPEN=69, 
		SCAN=70, UNTIL=71, DEACT=72, INPUT=73, PUT=74, STOP=75, UPCASE=76, DEL=77, 
		KCMPRES=78, NRBQUOTE=79, STR=80, WHILE=81, DELETE=82, KINDEX=83, NRQUOTE=84, 
		SYSCALL=85, WINDOW=86, DISPLAY=87, KLEFT=88, METASYM=89, SUBSTR=90, DMIDSPLY=91, 
		KLENGTH=92, QKCMPRES=93, SUPERQ=94, DMISPLIT=95, KSCAN=96, QKLEFT=97, 
		SYMDEL=98, DO=99, KSUBSTR=100, QKSCAN=101, SYMEXIST=102, EDIT=103, KTRIM=104, 
		QKSUBSTR=105, SYMGLOBL=106, ELSE=107, KUPCASE=108, QKTRIM=109, SYMLOCAL=110, 
		Tk_NULL=111, CANCEL=112, NOLIST=113, ARRAY=114, ARRAY_NUMERIC_ELEMENTS=115, 
		ARRAY_CHARACTER_ELEMENTS=116, ARRAY_ALL_ELEMENTS=117, GROUPFORMAT=118, 
		NOTSORTED=119, DESCENDING=120, CALL=121, DEBUG=122, NESTING=123, STACK=124, 
		READ=125, PW=126, SOURCE=127, VIEW=128, PGM=129, ENCRYPT=130, NOSAVE=131, 
		DATALINES=132, CARDS=133, LINES=134, DATALINES4=135, CARDS4=136, LINES4=137, 
		END_DATALINES4=138, ALTER=139, DISK=140, DUMMY=141, GTERM=142, PIPE=143, 
		PLOTTER=144, PRINTER=145, TAPE=146, TEMP=147, TERMINAL=148, UPRINTER=149, 
		DSD=150, EXPANDTABS=151, NOEXPANDTABS=152, FLOWOVER=153, MISSOVER=154, 
		PAD=155, NOPAD=156, SCANOVER=157, SHAREBUFFERS=158, STOPOVER=159, TRUNCOVER=160, 
		V_INFILE_=161, INPUT_ODS=162, DATE=163, DATETIME=164, DDMMYY=165, INFORMAT_COMMA=166, 
		INFORMAT_CHAR=167, DROP=168, PROC=169, ANOVA=170, MEANS=171, REG=172, 
		CORR=173, SGPLOT=174, PRINT=175, DATA=176, GLM=177, FREQ=178, SQL=179, 
		UNIVARIATE=180, NPAR1WAY=181, IMPORT=182, SORT=183, DATASETS=184, TABULATE=185, 
		RANK=186, CHART=187, LOGISTIC=188, SURVEYSELECT=189, Informat=190, DOLLAR=191, 
		EQ=192, NE=193, GT=194, LT=195, GE=196, LE=197, IN=198, EQC=199, NEC=200, 
		GTC=201, LTC=202, GEC=203, LEC=204, INColon=205, AND=206, OR=207, NOT=208, 
		MIN=209, MAX=210, DateLiteral=211, TimeLiteral=212, DateTimeLiteral=213, 
		BitLiteral=214, NameLiteral=215, HexLiteral=216, STRINGLITERAL=217, INT=218, 
		FloatingPointLiteral=219, Identifier=220, DOT=221, AT=222, EQUAL=223, 
		COMMA=224, LBracket=225, RBracket=226, WS=227, COMMENT=228, LINE_COMMENT=229;
	public static final int
		RULE_expression = 0, RULE_expressionList = 1, RULE_of_var_list = 2, RULE_identifiers_list = 3, 
		RULE_in_var_list = 4, RULE_colonInts = 5, RULE_literal = 6, RULE_variables = 7;
	private static String[] makeRuleNames() {
		return new String[] {
			"expression", "expressionList", "of_var_list", "identifiers_list", "in_var_list", 
			"colonInts", "literal", "variables"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'('", "')'", "'{'", "'}'", "'['", "']'", "'**'", "'+'", "'-'", 
			"'*'", "'/'", "'%'", "'||'", "'!!'", "'of'", "':'", null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, "';;;;'", 
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
			null, null, null, null, null, "ABEND", "END", "LENGTH", "QKUPCASE", "SYSEVALF", 
			"ABORT", "EVAL", "LET", "QSCAN", "SYSEXEC", "ACT", "FILE", "LIST", "QSUBSTR", 
			"SYSFUNC", "ACTIVATE", "GLOBAL", "LISTM", "QSYSFUNC", "SYSGET", "BQUOTE", 
			"GO", "LOCAL", "QUOTE", "SYSRPUT", "BY", "GOTO", "MACRO", "QUPCASE", 
			"THEN", "CLEAR", "IF", "MEND", "RESOLVE", "TO", "CLOSE", "INC", "PAUSE", 
			"RETURN", "TSO", "CMS", "INCLUDE", "NRSTR", "RUN", "UNQUOTE", "COMANDR", 
			"INDEX", "ON", "SAVE", "UNSTR", "COPY", "INFILE", "OPEN", "SCAN", "UNTIL", 
			"DEACT", "INPUT", "PUT", "STOP", "UPCASE", "DEL", "KCMPRES", "NRBQUOTE", 
			"STR", "WHILE", "DELETE", "KINDEX", "NRQUOTE", "SYSCALL", "WINDOW", "DISPLAY", 
			"KLEFT", "METASYM", "SUBSTR", "DMIDSPLY", "KLENGTH", "QKCMPRES", "SUPERQ", 
			"DMISPLIT", "KSCAN", "QKLEFT", "SYMDEL", "DO", "KSUBSTR", "QKSCAN", "SYMEXIST", 
			"EDIT", "KTRIM", "QKSUBSTR", "SYMGLOBL", "ELSE", "KUPCASE", "QKTRIM", 
			"SYMLOCAL", "Tk_NULL", "CANCEL", "NOLIST", "ARRAY", "ARRAY_NUMERIC_ELEMENTS", 
			"ARRAY_CHARACTER_ELEMENTS", "ARRAY_ALL_ELEMENTS", "GROUPFORMAT", "NOTSORTED", 
			"DESCENDING", "CALL", "DEBUG", "NESTING", "STACK", "READ", "PW", "SOURCE", 
			"VIEW", "PGM", "ENCRYPT", "NOSAVE", "DATALINES", "CARDS", "LINES", "DATALINES4", 
			"CARDS4", "LINES4", "END_DATALINES4", "ALTER", "DISK", "DUMMY", "GTERM", 
			"PIPE", "PLOTTER", "PRINTER", "TAPE", "TEMP", "TERMINAL", "UPRINTER", 
			"DSD", "EXPANDTABS", "NOEXPANDTABS", "FLOWOVER", "MISSOVER", "PAD", "NOPAD", 
			"SCANOVER", "SHAREBUFFERS", "STOPOVER", "TRUNCOVER", "V_INFILE_", "INPUT_ODS", 
			"DATE", "DATETIME", "DDMMYY", "INFORMAT_COMMA", "INFORMAT_CHAR", "DROP", 
			"PROC", "ANOVA", "MEANS", "REG", "CORR", "SGPLOT", "PRINT", "DATA", "GLM", 
			"FREQ", "SQL", "UNIVARIATE", "NPAR1WAY", "IMPORT", "SORT", "DATASETS", 
			"TABULATE", "RANK", "CHART", "LOGISTIC", "SURVEYSELECT", "Informat", 
			"DOLLAR", "EQ", "NE", "GT", "LT", "GE", "LE", "IN", "EQC", "NEC", "GTC", 
			"LTC", "GEC", "LEC", "INColon", "AND", "OR", "NOT", "MIN", "MAX", "DateLiteral", 
			"TimeLiteral", "DateTimeLiteral", "BitLiteral", "NameLiteral", "HexLiteral", 
			"STRINGLITERAL", "INT", "FloatingPointLiteral", "Identifier", "DOT", 
			"AT", "EQUAL", "COMMA", "LBracket", "RBracket", "WS", "COMMENT", "LINE_COMMENT"
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
	public String getGrammarFileName() { return "CommonGrammar.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public CommonGrammarParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionContext extends ParserRuleContext {
		public LiteralContext literal() {
			return getRuleContext(LiteralContext.class,0);
		}
		public TerminalNode Identifier() { return getToken(CommonGrammarParser.Identifier, 0); }
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode NOT() { return getToken(CommonGrammarParser.NOT, 0); }
		public TerminalNode MIN() { return getToken(CommonGrammarParser.MIN, 0); }
		public TerminalNode MAX() { return getToken(CommonGrammarParser.MAX, 0); }
		public TerminalNode EQ() { return getToken(CommonGrammarParser.EQ, 0); }
		public TerminalNode NE() { return getToken(CommonGrammarParser.NE, 0); }
		public TerminalNode GT() { return getToken(CommonGrammarParser.GT, 0); }
		public TerminalNode LT() { return getToken(CommonGrammarParser.LT, 0); }
		public TerminalNode GE() { return getToken(CommonGrammarParser.GE, 0); }
		public TerminalNode LE() { return getToken(CommonGrammarParser.LE, 0); }
		public TerminalNode EQC() { return getToken(CommonGrammarParser.EQC, 0); }
		public TerminalNode NEC() { return getToken(CommonGrammarParser.NEC, 0); }
		public TerminalNode GTC() { return getToken(CommonGrammarParser.GTC, 0); }
		public TerminalNode LTC() { return getToken(CommonGrammarParser.LTC, 0); }
		public TerminalNode GEC() { return getToken(CommonGrammarParser.GEC, 0); }
		public TerminalNode LEC() { return getToken(CommonGrammarParser.LEC, 0); }
		public TerminalNode AND() { return getToken(CommonGrammarParser.AND, 0); }
		public TerminalNode OR() { return getToken(CommonGrammarParser.OR, 0); }
		public TerminalNode EQUAL() { return getToken(CommonGrammarParser.EQUAL, 0); }
		public ExpressionListContext expressionList() {
			return getRuleContext(ExpressionListContext.class,0);
		}
		public In_var_listContext in_var_list() {
			return getRuleContext(In_var_listContext.class,0);
		}
		public TerminalNode IN() { return getToken(CommonGrammarParser.IN, 0); }
		public TerminalNode INColon() { return getToken(CommonGrammarParser.INColon, 0); }
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CommonGrammarListener ) ((CommonGrammarListener)listener).enterExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CommonGrammarListener ) ((CommonGrammarListener)listener).exitExpression(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CommonGrammarVisitor ) return ((CommonGrammarVisitor<? extends T>)visitor).visitExpression(this);
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
		int _startState = 0;
		enterRecursionRule(_localctx, 0, RULE_expression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(27);
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
				setState(17);
				literal();
				}
				break;
			case Identifier:
				{
				setState(18);
				match(Identifier);
				}
				break;
			case T__0:
				{
				setState(19);
				match(T__0);
				setState(20);
				expression(0);
				setState(21);
				match(T__1);
				}
				break;
			case T__7:
			case T__8:
				{
				setState(23);
				_la = _input.LA(1);
				if ( !(_la==T__7 || _la==T__8) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(24);
				expression(12);
				}
				break;
			case NOT:
				{
				setState(25);
				match(NOT);
				setState(26);
				expression(11);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(80);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,3,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(78);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
					case 1:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(29);
						if (!(precpred(_ctx, 13))) throw new FailedPredicateException(this, "precpred(_ctx, 13)");
						setState(30);
						match(T__6);
						setState(31);
						expression(13);
						}
						break;
					case 2:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(32);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(33);
						match(MIN);
						setState(34);
						expression(11);
						}
						break;
					case 3:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(35);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(36);
						match(MAX);
						setState(37);
						expression(10);
						}
						break;
					case 4:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(38);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(39);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 7168L) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(40);
						expression(9);
						}
						break;
					case 5:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(41);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(42);
						_la = _input.LA(1);
						if ( !(_la==T__7 || _la==T__8) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(43);
						expression(8);
						}
						break;
					case 6:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(44);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(45);
						_la = _input.LA(1);
						if ( !(_la==T__12 || _la==T__13) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(46);
						expression(7);
						}
						break;
					case 7:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(47);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(48);
						_la = _input.LA(1);
						if ( !(((((_la - 192)) & ~0x3f) == 0 && ((1L << (_la - 192)) & 63L) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(49);
						expression(6);
						}
						break;
					case 8:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(50);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(51);
						_la = _input.LA(1);
						if ( !(((((_la - 199)) & ~0x3f) == 0 && ((1L << (_la - 199)) & 63L) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(52);
						expression(5);
						}
						break;
					case 9:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(53);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(54);
						_la = _input.LA(1);
						if ( !(_la==AND || _la==OR) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(55);
						expression(3);
						}
						break;
					case 10:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(56);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(57);
						match(EQUAL);
						setState(58);
						expression(1);
						}
						break;
					case 11:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(59);
						if (!(precpred(_ctx, 16))) throw new FailedPredicateException(this, "precpred(_ctx, 16)");
						setState(60);
						match(T__0);
						setState(62);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 33538L) != 0) || ((((_la - 208)) & ~0x3f) == 0 && ((1L << (_la - 208)) & 16377L) != 0)) {
							{
							setState(61);
							expressionList(0);
							}
						}

						setState(64);
						match(T__1);
						}
						break;
					case 12:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(65);
						if (!(precpred(_ctx, 15))) throw new FailedPredicateException(this, "precpred(_ctx, 15)");
						setState(66);
						match(T__2);
						setState(67);
						expression(0);
						setState(68);
						match(T__3);
						}
						break;
					case 13:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(70);
						if (!(precpred(_ctx, 14))) throw new FailedPredicateException(this, "precpred(_ctx, 14)");
						setState(71);
						match(T__4);
						setState(72);
						expression(0);
						setState(73);
						match(T__5);
						}
						break;
					case 14:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(75);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(76);
						_la = _input.LA(1);
						if ( !(_la==IN || _la==INColon) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(77);
						in_var_list();
						}
						break;
					}
					} 
				}
				setState(82);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,3,_ctx);
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

	@SuppressWarnings("CheckReturnValue")
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
		public List<TerminalNode> COMMA() { return getTokens(CommonGrammarParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(CommonGrammarParser.COMMA, i);
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
			if ( listener instanceof CommonGrammarListener ) ((CommonGrammarListener)listener).enterExpressionList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CommonGrammarListener ) ((CommonGrammarListener)listener).exitExpressionList(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CommonGrammarVisitor ) return ((CommonGrammarVisitor<? extends T>)visitor).visitExpressionList(this);
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
		int _startState = 2;
		enterRecursionRule(_localctx, 2, RULE_expressionList, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(86);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__0:
			case T__7:
			case T__8:
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
				setState(84);
				expression(0);
				}
				break;
			case T__14:
				{
				setState(85);
				of_var_list();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(95);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(88);
					match(COMMA);
					setState(91);
					_errHandler.sync(this);
					switch (_input.LA(1)) {
					case T__0:
					case T__7:
					case T__8:
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
						setState(89);
						expression(0);
						}
						break;
					case T__14:
						{
						setState(90);
						of_var_list();
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					}
					} 
				}
				setState(97);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			}
			}
			_ctx.stop = _input.LT(-1);
			setState(107);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ExpressionListContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_expressionList);
					setState(98);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(100); 
					_errHandler.sync(this);
					_la = _input.LA(1);
					do {
						{
						{
						setState(99);
						match(COMMA);
						}
						}
						setState(102); 
						_errHandler.sync(this);
						_la = _input.LA(1);
					} while ( _la==COMMA );
					setState(104);
					expressionList(2);
					}
					} 
				}
				setState(109);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
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

	@SuppressWarnings("CheckReturnValue")
	public static class Of_var_listContext extends ParserRuleContext {
		public List<TerminalNode> Identifier() { return getTokens(CommonGrammarParser.Identifier); }
		public TerminalNode Identifier(int i) {
			return getToken(CommonGrammarParser.Identifier, i);
		}
		public List<TerminalNode> COMMA() { return getTokens(CommonGrammarParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(CommonGrammarParser.COMMA, i);
		}
		public Of_var_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_of_var_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CommonGrammarListener ) ((CommonGrammarListener)listener).enterOf_var_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CommonGrammarListener ) ((CommonGrammarListener)listener).exitOf_var_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CommonGrammarVisitor ) return ((CommonGrammarVisitor<? extends T>)visitor).visitOf_var_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Of_var_listContext of_var_list() throws RecognitionException {
		Of_var_listContext _localctx = new Of_var_listContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_of_var_list);
		int _la;
		try {
			int _alt;
			setState(140);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,12,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(110);
				match(T__14);
				{
				setState(111);
				match(Identifier);
				setState(112);
				match(T__8);
				setState(113);
				match(Identifier);
				}
				setState(124);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(117);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if (_la==COMMA) {
							{
							setState(115);
							match(COMMA);
							setState(116);
							match(T__14);
							}
						}

						{
						setState(119);
						match(Identifier);
						setState(120);
						match(T__8);
						setState(121);
						match(Identifier);
						}
						}
						} 
					}
					setState(126);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(127);
				match(T__14);
				setState(128);
				match(Identifier);
				setState(132);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,11,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(129);
						match(Identifier);
						}
						} 
					}
					setState(134);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,11,_ctx);
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(135);
				match(T__14);
				setState(136);
				match(Identifier);
				setState(137);
				match(T__4);
				setState(138);
				match(T__9);
				setState(139);
				match(T__5);
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

	@SuppressWarnings("CheckReturnValue")
	public static class Identifiers_listContext extends ParserRuleContext {
		public List<TerminalNode> Identifier() { return getTokens(CommonGrammarParser.Identifier); }
		public TerminalNode Identifier(int i) {
			return getToken(CommonGrammarParser.Identifier, i);
		}
		public Identifiers_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_identifiers_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CommonGrammarListener ) ((CommonGrammarListener)listener).enterIdentifiers_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CommonGrammarListener ) ((CommonGrammarListener)listener).exitIdentifiers_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CommonGrammarVisitor ) return ((CommonGrammarVisitor<? extends T>)visitor).visitIdentifiers_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Identifiers_listContext identifiers_list() throws RecognitionException {
		Identifiers_listContext _localctx = new Identifiers_listContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_identifiers_list);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(146); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				setState(146);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
				case 1:
					{
					setState(142);
					match(Identifier);
					}
					break;
				case 2:
					{
					setState(143);
					match(Identifier);
					setState(144);
					match(T__8);
					setState(145);
					match(Identifier);
					}
					break;
				}
				}
				setState(148); 
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

	@SuppressWarnings("CheckReturnValue")
	public static class In_var_listContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(CommonGrammarParser.Identifier, 0); }
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
		public List<TerminalNode> COMMA() { return getTokens(CommonGrammarParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(CommonGrammarParser.COMMA, i);
		}
		public In_var_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_in_var_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CommonGrammarListener ) ((CommonGrammarListener)listener).enterIn_var_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CommonGrammarListener ) ((CommonGrammarListener)listener).exitIn_var_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CommonGrammarVisitor ) return ((CommonGrammarVisitor<? extends T>)visitor).visitIn_var_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final In_var_listContext in_var_list() throws RecognitionException {
		In_var_listContext _localctx = new In_var_listContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_in_var_list);
		int _la;
		try {
			setState(168);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Identifier:
				enterOuterAlt(_localctx, 1);
				{
				setState(150);
				match(Identifier);
				}
				break;
			case T__0:
				enterOuterAlt(_localctx, 2);
				{
				setState(151);
				match(T__0);
				setState(154);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
				case 1:
					{
					setState(152);
					literal();
					}
					break;
				case 2:
					{
					setState(153);
					colonInts();
					}
					break;
				}
				setState(163);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMMA) {
					{
					{
					setState(156);
					match(COMMA);
					setState(159);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,16,_ctx) ) {
					case 1:
						{
						setState(157);
						literal();
						}
						break;
					case 2:
						{
						setState(158);
						colonInts();
						}
						break;
					}
					}
					}
					setState(165);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(166);
				match(T__1);
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

	@SuppressWarnings("CheckReturnValue")
	public static class ColonIntsContext extends ParserRuleContext {
		public List<TerminalNode> INT() { return getTokens(CommonGrammarParser.INT); }
		public TerminalNode INT(int i) {
			return getToken(CommonGrammarParser.INT, i);
		}
		public ColonIntsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_colonInts; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CommonGrammarListener ) ((CommonGrammarListener)listener).enterColonInts(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CommonGrammarListener ) ((CommonGrammarListener)listener).exitColonInts(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CommonGrammarVisitor ) return ((CommonGrammarVisitor<? extends T>)visitor).visitColonInts(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ColonIntsContext colonInts() throws RecognitionException {
		ColonIntsContext _localctx = new ColonIntsContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_colonInts);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(170);
			match(INT);
			setState(171);
			match(T__15);
			setState(172);
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

	@SuppressWarnings("CheckReturnValue")
	public static class LiteralContext extends ParserRuleContext {
		public TerminalNode INT() { return getToken(CommonGrammarParser.INT, 0); }
		public TerminalNode FloatingPointLiteral() { return getToken(CommonGrammarParser.FloatingPointLiteral, 0); }
		public TerminalNode STRINGLITERAL() { return getToken(CommonGrammarParser.STRINGLITERAL, 0); }
		public TerminalNode DateLiteral() { return getToken(CommonGrammarParser.DateLiteral, 0); }
		public TerminalNode TimeLiteral() { return getToken(CommonGrammarParser.TimeLiteral, 0); }
		public TerminalNode DateTimeLiteral() { return getToken(CommonGrammarParser.DateTimeLiteral, 0); }
		public TerminalNode BitLiteral() { return getToken(CommonGrammarParser.BitLiteral, 0); }
		public TerminalNode NameLiteral() { return getToken(CommonGrammarParser.NameLiteral, 0); }
		public TerminalNode HexLiteral() { return getToken(CommonGrammarParser.HexLiteral, 0); }
		public TerminalNode DOT() { return getToken(CommonGrammarParser.DOT, 0); }
		public LiteralContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_literal; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CommonGrammarListener ) ((CommonGrammarListener)listener).enterLiteral(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CommonGrammarListener ) ((CommonGrammarListener)listener).exitLiteral(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CommonGrammarVisitor ) return ((CommonGrammarVisitor<? extends T>)visitor).visitLiteral(this);
			else return visitor.visitChildren(this);
		}
	}

	public final LiteralContext literal() throws RecognitionException {
		LiteralContext _localctx = new LiteralContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_literal);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(174);
			_la = _input.LA(1);
			if ( !(((((_la - 211)) & ~0x3f) == 0 && ((1L << (_la - 211)) & 1535L) != 0)) ) {
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

	@SuppressWarnings("CheckReturnValue")
	public static class VariablesContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(CommonGrammarParser.Identifier, 0); }
		public TerminalNode DATE() { return getToken(CommonGrammarParser.DATE, 0); }
		public TerminalNode ALTER() { return getToken(CommonGrammarParser.ALTER, 0); }
		public TerminalNode DROP() { return getToken(CommonGrammarParser.DROP, 0); }
		public List<VariablesContext> variables() {
			return getRuleContexts(VariablesContext.class);
		}
		public VariablesContext variables(int i) {
			return getRuleContext(VariablesContext.class,i);
		}
		public TerminalNode DOT() { return getToken(CommonGrammarParser.DOT, 0); }
		public VariablesContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variables; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CommonGrammarListener ) ((CommonGrammarListener)listener).enterVariables(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CommonGrammarListener ) ((CommonGrammarListener)listener).exitVariables(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CommonGrammarVisitor ) return ((CommonGrammarVisitor<? extends T>)visitor).visitVariables(this);
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
		int _startState = 14;
		enterRecursionRule(_localctx, 14, RULE_variables, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(181);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Identifier:
				{
				setState(177);
				match(Identifier);
				}
				break;
			case DATE:
				{
				setState(178);
				match(DATE);
				}
				break;
			case ALTER:
				{
				setState(179);
				match(ALTER);
				}
				break;
			case DROP:
				{
				setState(180);
				match(DROP);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(188);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new VariablesContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_variables);
					setState(183);
					if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
					setState(184);
					match(DOT);
					setState(185);
					variables(6);
					}
					} 
				}
				setState(190);
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

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 0:
			return expression_sempred((ExpressionContext)_localctx, predIndex);
		case 1:
			return expressionList_sempred((ExpressionListContext)_localctx, predIndex);
		case 7:
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
		"\u0004\u0001\u00e5\u00c0\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001"+
		"\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004"+
		"\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007"+
		"\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0003\u0000"+
		"\u001c\b\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0003\u0000?\b\u0000"+
		"\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0000\u0005\u0000O\b\u0000\n\u0000\f\u0000R\t\u0000"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0003\u0001W\b\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0003\u0001\\\b\u0001\u0005\u0001^\b\u0001\n"+
		"\u0001\f\u0001a\t\u0001\u0001\u0001\u0001\u0001\u0004\u0001e\b\u0001\u000b"+
		"\u0001\f\u0001f\u0001\u0001\u0005\u0001j\b\u0001\n\u0001\f\u0001m\t\u0001"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0003\u0002v\b\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0005\u0002{\b\u0002\n\u0002\f\u0002~\t\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0005\u0002\u0083\b\u0002\n\u0002\f\u0002\u0086\t\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0003\u0002\u008d"+
		"\b\u0002\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0004\u0003\u0093"+
		"\b\u0003\u000b\u0003\f\u0003\u0094\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0003\u0004\u009b\b\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0003\u0004\u00a0\b\u0004\u0005\u0004\u00a2\b\u0004\n\u0004\f\u0004\u00a5"+
		"\t\u0004\u0001\u0004\u0001\u0004\u0003\u0004\u00a9\b\u0004\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0006\u0001\u0006\u0001\u0007"+
		"\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0003\u0007\u00b6\b\u0007"+
		"\u0001\u0007\u0001\u0007\u0001\u0007\u0005\u0007\u00bb\b\u0007\n\u0007"+
		"\f\u0007\u00be\t\u0007\u0001\u0007\u0000\u0003\u0000\u0002\u000e\b\u0000"+
		"\u0002\u0004\u0006\b\n\f\u000e\u0000\b\u0001\u0000\b\t\u0001\u0000\n\f"+
		"\u0001\u0000\r\u000e\u0001\u0000\u00c0\u00c5\u0001\u0000\u00c7\u00cc\u0001"+
		"\u0000\u00ce\u00cf\u0002\u0000\u00c6\u00c6\u00cd\u00cd\u0002\u0000\u00d3"+
		"\u00db\u00dd\u00dd\u00de\u0000\u001b\u0001\u0000\u0000\u0000\u0002S\u0001"+
		"\u0000\u0000\u0000\u0004\u008c\u0001\u0000\u0000\u0000\u0006\u0092\u0001"+
		"\u0000\u0000\u0000\b\u00a8\u0001\u0000\u0000\u0000\n\u00aa\u0001\u0000"+
		"\u0000\u0000\f\u00ae\u0001\u0000\u0000\u0000\u000e\u00b5\u0001\u0000\u0000"+
		"\u0000\u0010\u0011\u0006\u0000\uffff\uffff\u0000\u0011\u001c\u0003\f\u0006"+
		"\u0000\u0012\u001c\u0005\u00dc\u0000\u0000\u0013\u0014\u0005\u0001\u0000"+
		"\u0000\u0014\u0015\u0003\u0000\u0000\u0000\u0015\u0016\u0005\u0002\u0000"+
		"\u0000\u0016\u001c\u0001\u0000\u0000\u0000\u0017\u0018\u0007\u0000\u0000"+
		"\u0000\u0018\u001c\u0003\u0000\u0000\f\u0019\u001a\u0005\u00d0\u0000\u0000"+
		"\u001a\u001c\u0003\u0000\u0000\u000b\u001b\u0010\u0001\u0000\u0000\u0000"+
		"\u001b\u0012\u0001\u0000\u0000\u0000\u001b\u0013\u0001\u0000\u0000\u0000"+
		"\u001b\u0017\u0001\u0000\u0000\u0000\u001b\u0019\u0001\u0000\u0000\u0000"+
		"\u001cP\u0001\u0000\u0000\u0000\u001d\u001e\n\r\u0000\u0000\u001e\u001f"+
		"\u0005\u0007\u0000\u0000\u001fO\u0003\u0000\u0000\r !\n\n\u0000\u0000"+
		"!\"\u0005\u00d1\u0000\u0000\"O\u0003\u0000\u0000\u000b#$\n\t\u0000\u0000"+
		"$%\u0005\u00d2\u0000\u0000%O\u0003\u0000\u0000\n&\'\n\b\u0000\u0000\'"+
		"(\u0007\u0001\u0000\u0000(O\u0003\u0000\u0000\t)*\n\u0007\u0000\u0000"+
		"*+\u0007\u0000\u0000\u0000+O\u0003\u0000\u0000\b,-\n\u0006\u0000\u0000"+
		"-.\u0007\u0002\u0000\u0000.O\u0003\u0000\u0000\u0007/0\n\u0005\u0000\u0000"+
		"01\u0007\u0003\u0000\u00001O\u0003\u0000\u0000\u000623\n\u0004\u0000\u0000"+
		"34\u0007\u0004\u0000\u00004O\u0003\u0000\u0000\u000556\n\u0002\u0000\u0000"+
		"67\u0007\u0005\u0000\u00007O\u0003\u0000\u0000\u000389\n\u0001\u0000\u0000"+
		"9:\u0005\u00df\u0000\u0000:O\u0003\u0000\u0000\u0001;<\n\u0010\u0000\u0000"+
		"<>\u0005\u0001\u0000\u0000=?\u0003\u0002\u0001\u0000>=\u0001\u0000\u0000"+
		"\u0000>?\u0001\u0000\u0000\u0000?@\u0001\u0000\u0000\u0000@O\u0005\u0002"+
		"\u0000\u0000AB\n\u000f\u0000\u0000BC\u0005\u0003\u0000\u0000CD\u0003\u0000"+
		"\u0000\u0000DE\u0005\u0004\u0000\u0000EO\u0001\u0000\u0000\u0000FG\n\u000e"+
		"\u0000\u0000GH\u0005\u0005\u0000\u0000HI\u0003\u0000\u0000\u0000IJ\u0005"+
		"\u0006\u0000\u0000JO\u0001\u0000\u0000\u0000KL\n\u0003\u0000\u0000LM\u0007"+
		"\u0006\u0000\u0000MO\u0003\b\u0004\u0000N\u001d\u0001\u0000\u0000\u0000"+
		"N \u0001\u0000\u0000\u0000N#\u0001\u0000\u0000\u0000N&\u0001\u0000\u0000"+
		"\u0000N)\u0001\u0000\u0000\u0000N,\u0001\u0000\u0000\u0000N/\u0001\u0000"+
		"\u0000\u0000N2\u0001\u0000\u0000\u0000N5\u0001\u0000\u0000\u0000N8\u0001"+
		"\u0000\u0000\u0000N;\u0001\u0000\u0000\u0000NA\u0001\u0000\u0000\u0000"+
		"NF\u0001\u0000\u0000\u0000NK\u0001\u0000\u0000\u0000OR\u0001\u0000\u0000"+
		"\u0000PN\u0001\u0000\u0000\u0000PQ\u0001\u0000\u0000\u0000Q\u0001\u0001"+
		"\u0000\u0000\u0000RP\u0001\u0000\u0000\u0000SV\u0006\u0001\uffff\uffff"+
		"\u0000TW\u0003\u0000\u0000\u0000UW\u0003\u0004\u0002\u0000VT\u0001\u0000"+
		"\u0000\u0000VU\u0001\u0000\u0000\u0000W_\u0001\u0000\u0000\u0000X[\u0005"+
		"\u00e0\u0000\u0000Y\\\u0003\u0000\u0000\u0000Z\\\u0003\u0004\u0002\u0000"+
		"[Y\u0001\u0000\u0000\u0000[Z\u0001\u0000\u0000\u0000\\^\u0001\u0000\u0000"+
		"\u0000]X\u0001\u0000\u0000\u0000^a\u0001\u0000\u0000\u0000_]\u0001\u0000"+
		"\u0000\u0000_`\u0001\u0000\u0000\u0000`k\u0001\u0000\u0000\u0000a_\u0001"+
		"\u0000\u0000\u0000bd\n\u0001\u0000\u0000ce\u0005\u00e0\u0000\u0000dc\u0001"+
		"\u0000\u0000\u0000ef\u0001\u0000\u0000\u0000fd\u0001\u0000\u0000\u0000"+
		"fg\u0001\u0000\u0000\u0000gh\u0001\u0000\u0000\u0000hj\u0003\u0002\u0001"+
		"\u0002ib\u0001\u0000\u0000\u0000jm\u0001\u0000\u0000\u0000ki\u0001\u0000"+
		"\u0000\u0000kl\u0001\u0000\u0000\u0000l\u0003\u0001\u0000\u0000\u0000"+
		"mk\u0001\u0000\u0000\u0000no\u0005\u000f\u0000\u0000op\u0005\u00dc\u0000"+
		"\u0000pq\u0005\t\u0000\u0000qr\u0005\u00dc\u0000\u0000r|\u0001\u0000\u0000"+
		"\u0000st\u0005\u00e0\u0000\u0000tv\u0005\u000f\u0000\u0000us\u0001\u0000"+
		"\u0000\u0000uv\u0001\u0000\u0000\u0000vw\u0001\u0000\u0000\u0000wx\u0005"+
		"\u00dc\u0000\u0000xy\u0005\t\u0000\u0000y{\u0005\u00dc\u0000\u0000zu\u0001"+
		"\u0000\u0000\u0000{~\u0001\u0000\u0000\u0000|z\u0001\u0000\u0000\u0000"+
		"|}\u0001\u0000\u0000\u0000}\u008d\u0001\u0000\u0000\u0000~|\u0001\u0000"+
		"\u0000\u0000\u007f\u0080\u0005\u000f\u0000\u0000\u0080\u0084\u0005\u00dc"+
		"\u0000\u0000\u0081\u0083\u0005\u00dc\u0000\u0000\u0082\u0081\u0001\u0000"+
		"\u0000\u0000\u0083\u0086\u0001\u0000\u0000\u0000\u0084\u0082\u0001\u0000"+
		"\u0000\u0000\u0084\u0085\u0001\u0000\u0000\u0000\u0085\u008d\u0001\u0000"+
		"\u0000\u0000\u0086\u0084\u0001\u0000\u0000\u0000\u0087\u0088\u0005\u000f"+
		"\u0000\u0000\u0088\u0089\u0005\u00dc\u0000\u0000\u0089\u008a\u0005\u0005"+
		"\u0000\u0000\u008a\u008b\u0005\n\u0000\u0000\u008b\u008d\u0005\u0006\u0000"+
		"\u0000\u008cn\u0001\u0000\u0000\u0000\u008c\u007f\u0001\u0000\u0000\u0000"+
		"\u008c\u0087\u0001\u0000\u0000\u0000\u008d\u0005\u0001\u0000\u0000\u0000"+
		"\u008e\u0093\u0005\u00dc\u0000\u0000\u008f\u0090\u0005\u00dc\u0000\u0000"+
		"\u0090\u0091\u0005\t\u0000\u0000\u0091\u0093\u0005\u00dc\u0000\u0000\u0092"+
		"\u008e\u0001\u0000\u0000\u0000\u0092\u008f\u0001\u0000\u0000\u0000\u0093"+
		"\u0094\u0001\u0000\u0000\u0000\u0094\u0092\u0001\u0000\u0000\u0000\u0094"+
		"\u0095\u0001\u0000\u0000\u0000\u0095\u0007\u0001\u0000\u0000\u0000\u0096"+
		"\u00a9\u0005\u00dc\u0000\u0000\u0097\u009a\u0005\u0001\u0000\u0000\u0098"+
		"\u009b\u0003\f\u0006\u0000\u0099\u009b\u0003\n\u0005\u0000\u009a\u0098"+
		"\u0001\u0000\u0000\u0000\u009a\u0099\u0001\u0000\u0000\u0000\u009b\u00a3"+
		"\u0001\u0000\u0000\u0000\u009c\u009f\u0005\u00e0\u0000\u0000\u009d\u00a0"+
		"\u0003\f\u0006\u0000\u009e\u00a0\u0003\n\u0005\u0000\u009f\u009d\u0001"+
		"\u0000\u0000\u0000\u009f\u009e\u0001\u0000\u0000\u0000\u00a0\u00a2\u0001"+
		"\u0000\u0000\u0000\u00a1\u009c\u0001\u0000\u0000\u0000\u00a2\u00a5\u0001"+
		"\u0000\u0000\u0000\u00a3\u00a1\u0001\u0000\u0000\u0000\u00a3\u00a4\u0001"+
		"\u0000\u0000\u0000\u00a4\u00a6\u0001\u0000\u0000\u0000\u00a5\u00a3\u0001"+
		"\u0000\u0000\u0000\u00a6\u00a7\u0005\u0002\u0000\u0000\u00a7\u00a9\u0001"+
		"\u0000\u0000\u0000\u00a8\u0096\u0001\u0000\u0000\u0000\u00a8\u0097\u0001"+
		"\u0000\u0000\u0000\u00a9\t\u0001\u0000\u0000\u0000\u00aa\u00ab\u0005\u00da"+
		"\u0000\u0000\u00ab\u00ac\u0005\u0010\u0000\u0000\u00ac\u00ad\u0005\u00da"+
		"\u0000\u0000\u00ad\u000b\u0001\u0000\u0000\u0000\u00ae\u00af\u0007\u0007"+
		"\u0000\u0000\u00af\r\u0001\u0000\u0000\u0000\u00b0\u00b1\u0006\u0007\uffff"+
		"\uffff\u0000\u00b1\u00b6\u0005\u00dc\u0000\u0000\u00b2\u00b6\u0005\u00a3"+
		"\u0000\u0000\u00b3\u00b6\u0005\u008b\u0000\u0000\u00b4\u00b6\u0005\u00a8"+
		"\u0000\u0000\u00b5\u00b0\u0001\u0000\u0000\u0000\u00b5\u00b2\u0001\u0000"+
		"\u0000\u0000\u00b5\u00b3\u0001\u0000\u0000\u0000\u00b5\u00b4\u0001\u0000"+
		"\u0000\u0000\u00b6\u00bc\u0001\u0000\u0000\u0000\u00b7\u00b8\n\u0005\u0000"+
		"\u0000\u00b8\u00b9\u0005\u00dd\u0000\u0000\u00b9\u00bb\u0003\u000e\u0007"+
		"\u0006\u00ba\u00b7\u0001\u0000\u0000\u0000\u00bb\u00be\u0001\u0000\u0000"+
		"\u0000\u00bc\u00ba\u0001\u0000\u0000\u0000\u00bc\u00bd\u0001\u0000\u0000"+
		"\u0000\u00bd\u000f\u0001\u0000\u0000\u0000\u00be\u00bc\u0001\u0000\u0000"+
		"\u0000\u0015\u001b>NPV[_fku|\u0084\u008c\u0092\u0094\u009a\u009f\u00a3"+
		"\u00a8\u00b5\u00bc";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}