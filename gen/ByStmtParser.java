// Generated from /Users/sethtrojacek/IdeaProjects/jazz/src/main/antlr4/ByStmt.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class ByStmtParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

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
		RULE_by_main = 0, RULE_by_stmt = 1, RULE_expression = 2, RULE_expressionList = 3, 
		RULE_of_var_list = 4, RULE_identifiers_list = 5, RULE_in_var_list = 6, 
		RULE_colonInts = 7, RULE_literal = 8, RULE_variables = 9;
	private static String[] makeRuleNames() {
		return new String[] {
			"by_main", "by_stmt", "expression", "expressionList", "of_var_list", 
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
	public String getGrammarFileName() { return "ByStmt.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public ByStmtParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class By_mainContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(ByStmtParser.EOF, 0); }
		public List<By_stmtContext> by_stmt() {
			return getRuleContexts(By_stmtContext.class);
		}
		public By_stmtContext by_stmt(int i) {
			return getRuleContext(By_stmtContext.class,i);
		}
		public By_mainContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_by_main; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ByStmtListener ) ((ByStmtListener)listener).enterBy_main(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ByStmtListener ) ((ByStmtListener)listener).exitBy_main(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ByStmtVisitor ) return ((ByStmtVisitor<? extends T>)visitor).visitBy_main(this);
			else return visitor.visitChildren(this);
		}
	}

	public final By_mainContext by_main() throws RecognitionException {
		By_mainContext _localctx = new By_mainContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_by_main);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(23);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==BY) {
				{
				{
				setState(20);
				by_stmt();
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

	@SuppressWarnings("CheckReturnValue")
	public static class By_stmtContext extends ParserRuleContext {
		public TerminalNode BY() { return getToken(ByStmtParser.BY, 0); }
		public List<TerminalNode> Identifier() { return getTokens(ByStmtParser.Identifier); }
		public TerminalNode Identifier(int i) {
			return getToken(ByStmtParser.Identifier, i);
		}
		public TerminalNode NOTSORTED() { return getToken(ByStmtParser.NOTSORTED, 0); }
		public TerminalNode GROUPFORMAT() { return getToken(ByStmtParser.GROUPFORMAT, 0); }
		public List<TerminalNode> DESCENDING() { return getTokens(ByStmtParser.DESCENDING); }
		public TerminalNode DESCENDING(int i) {
			return getToken(ByStmtParser.DESCENDING, i);
		}
		public By_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_by_stmt; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ByStmtListener ) ((ByStmtListener)listener).enterBy_stmt(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ByStmtListener ) ((ByStmtListener)listener).exitBy_stmt(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ByStmtVisitor ) return ((ByStmtVisitor<? extends T>)visitor).visitBy_stmt(this);
			else return visitor.visitChildren(this);
		}
	}

	public final By_stmtContext by_stmt() throws RecognitionException {
		By_stmtContext _localctx = new By_stmtContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_by_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(28);
			match(BY);
			{
			setState(30);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==DESCENDING) {
				{
				setState(29);
				match(DESCENDING);
				}
			}

			setState(32);
			match(Identifier);
			}
			setState(40);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==DESCENDING || _la==Identifier) {
				{
				{
				setState(35);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==DESCENDING) {
					{
					setState(34);
					match(DESCENDING);
					}
				}

				setState(37);
				match(Identifier);
				}
				}
				setState(42);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(44);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==NOTSORTED) {
				{
				setState(43);
				match(NOTSORTED);
				}
			}

			setState(47);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==GROUPFORMAT) {
				{
				setState(46);
				match(GROUPFORMAT);
				}
			}

			setState(49);
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

	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionContext extends ParserRuleContext {
		public LiteralContext literal() {
			return getRuleContext(LiteralContext.class,0);
		}
		public TerminalNode Identifier() { return getToken(ByStmtParser.Identifier, 0); }
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode NOT() { return getToken(ByStmtParser.NOT, 0); }
		public TerminalNode MIN() { return getToken(ByStmtParser.MIN, 0); }
		public TerminalNode MAX() { return getToken(ByStmtParser.MAX, 0); }
		public TerminalNode EQ() { return getToken(ByStmtParser.EQ, 0); }
		public TerminalNode NE() { return getToken(ByStmtParser.NE, 0); }
		public TerminalNode GT() { return getToken(ByStmtParser.GT, 0); }
		public TerminalNode LT() { return getToken(ByStmtParser.LT, 0); }
		public TerminalNode GE() { return getToken(ByStmtParser.GE, 0); }
		public TerminalNode LE() { return getToken(ByStmtParser.LE, 0); }
		public TerminalNode EQC() { return getToken(ByStmtParser.EQC, 0); }
		public TerminalNode NEC() { return getToken(ByStmtParser.NEC, 0); }
		public TerminalNode GTC() { return getToken(ByStmtParser.GTC, 0); }
		public TerminalNode LTC() { return getToken(ByStmtParser.LTC, 0); }
		public TerminalNode GEC() { return getToken(ByStmtParser.GEC, 0); }
		public TerminalNode LEC() { return getToken(ByStmtParser.LEC, 0); }
		public TerminalNode AND() { return getToken(ByStmtParser.AND, 0); }
		public TerminalNode OR() { return getToken(ByStmtParser.OR, 0); }
		public TerminalNode EQUAL() { return getToken(ByStmtParser.EQUAL, 0); }
		public ExpressionListContext expressionList() {
			return getRuleContext(ExpressionListContext.class,0);
		}
		public In_var_listContext in_var_list() {
			return getRuleContext(In_var_listContext.class,0);
		}
		public TerminalNode IN() { return getToken(ByStmtParser.IN, 0); }
		public TerminalNode INColon() { return getToken(ByStmtParser.INColon, 0); }
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ByStmtListener ) ((ByStmtListener)listener).enterExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ByStmtListener ) ((ByStmtListener)listener).exitExpression(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ByStmtVisitor ) return ((ByStmtVisitor<? extends T>)visitor).visitExpression(this);
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
			setState(62);
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
				setState(52);
				literal();
				}
				break;
			case Identifier:
				{
				setState(53);
				match(Identifier);
				}
				break;
			case T__1:
				{
				setState(54);
				match(T__1);
				setState(55);
				expression(0);
				setState(56);
				match(T__2);
				}
				break;
			case T__8:
			case T__9:
				{
				setState(58);
				_la = _input.LA(1);
				if ( !(_la==T__8 || _la==T__9) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(59);
				expression(12);
				}
				break;
			case NOT:
				{
				setState(60);
				match(NOT);
				setState(61);
				expression(11);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(115);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,9,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(113);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
					case 1:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(64);
						if (!(precpred(_ctx, 13))) throw new FailedPredicateException(this, "precpred(_ctx, 13)");
						setState(65);
						match(T__7);
						setState(66);
						expression(13);
						}
						break;
					case 2:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(67);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(68);
						match(MIN);
						setState(69);
						expression(11);
						}
						break;
					case 3:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(70);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(71);
						match(MAX);
						setState(72);
						expression(10);
						}
						break;
					case 4:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(73);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(74);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 14336L) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(75);
						expression(9);
						}
						break;
					case 5:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(76);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(77);
						_la = _input.LA(1);
						if ( !(_la==T__8 || _la==T__9) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(78);
						expression(8);
						}
						break;
					case 6:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(79);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(80);
						_la = _input.LA(1);
						if ( !(_la==T__13 || _la==T__14) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(81);
						expression(7);
						}
						break;
					case 7:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(82);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(83);
						_la = _input.LA(1);
						if ( !(((((_la - 193)) & ~0x3f) == 0 && ((1L << (_la - 193)) & 63L) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(84);
						expression(6);
						}
						break;
					case 8:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(85);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(86);
						_la = _input.LA(1);
						if ( !(((((_la - 200)) & ~0x3f) == 0 && ((1L << (_la - 200)) & 63L) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(87);
						expression(5);
						}
						break;
					case 9:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(88);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(89);
						_la = _input.LA(1);
						if ( !(_la==AND || _la==OR) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(90);
						expression(3);
						}
						break;
					case 10:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(91);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(92);
						match(EQUAL);
						setState(93);
						expression(1);
						}
						break;
					case 11:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(94);
						if (!(precpred(_ctx, 16))) throw new FailedPredicateException(this, "precpred(_ctx, 16)");
						setState(95);
						match(T__1);
						setState(97);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 67076L) != 0) || ((((_la - 209)) & ~0x3f) == 0 && ((1L << (_la - 209)) & 16377L) != 0)) {
							{
							setState(96);
							expressionList(0);
							}
						}

						setState(99);
						match(T__2);
						}
						break;
					case 12:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(100);
						if (!(precpred(_ctx, 15))) throw new FailedPredicateException(this, "precpred(_ctx, 15)");
						setState(101);
						match(T__3);
						setState(102);
						expression(0);
						setState(103);
						match(T__4);
						}
						break;
					case 13:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(105);
						if (!(precpred(_ctx, 14))) throw new FailedPredicateException(this, "precpred(_ctx, 14)");
						setState(106);
						match(T__5);
						setState(107);
						expression(0);
						setState(108);
						match(T__6);
						}
						break;
					case 14:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(110);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(111);
						_la = _input.LA(1);
						if ( !(_la==IN || _la==INColon) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(112);
						in_var_list();
						}
						break;
					}
					} 
				}
				setState(117);
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
		public List<TerminalNode> COMMA() { return getTokens(ByStmtParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(ByStmtParser.COMMA, i);
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
			if ( listener instanceof ByStmtListener ) ((ByStmtListener)listener).enterExpressionList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ByStmtListener ) ((ByStmtListener)listener).exitExpressionList(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ByStmtVisitor ) return ((ByStmtVisitor<? extends T>)visitor).visitExpressionList(this);
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
			setState(121);
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
				setState(119);
				expression(0);
				}
				break;
			case T__15:
				{
				setState(120);
				of_var_list();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(130);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(123);
					match(COMMA);
					setState(126);
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
						setState(124);
						expression(0);
						}
						break;
					case T__15:
						{
						setState(125);
						of_var_list();
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					}
					} 
				}
				setState(132);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			}
			}
			_ctx.stop = _input.LT(-1);
			setState(142);
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
					setState(133);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(135); 
					_errHandler.sync(this);
					_la = _input.LA(1);
					do {
						{
						{
						setState(134);
						match(COMMA);
						}
						}
						setState(137); 
						_errHandler.sync(this);
						_la = _input.LA(1);
					} while ( _la==COMMA );
					setState(139);
					expressionList(2);
					}
					} 
				}
				setState(144);
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

	@SuppressWarnings("CheckReturnValue")
	public static class Of_var_listContext extends ParserRuleContext {
		public List<TerminalNode> Identifier() { return getTokens(ByStmtParser.Identifier); }
		public TerminalNode Identifier(int i) {
			return getToken(ByStmtParser.Identifier, i);
		}
		public List<TerminalNode> COMMA() { return getTokens(ByStmtParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(ByStmtParser.COMMA, i);
		}
		public Of_var_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_of_var_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ByStmtListener ) ((ByStmtListener)listener).enterOf_var_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ByStmtListener ) ((ByStmtListener)listener).exitOf_var_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ByStmtVisitor ) return ((ByStmtVisitor<? extends T>)visitor).visitOf_var_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Of_var_listContext of_var_list() throws RecognitionException {
		Of_var_listContext _localctx = new Of_var_listContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_of_var_list);
		int _la;
		try {
			int _alt;
			setState(175);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(145);
				match(T__15);
				{
				setState(146);
				match(Identifier);
				setState(147);
				match(T__9);
				setState(148);
				match(Identifier);
				}
				setState(159);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,16,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(152);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if (_la==COMMA) {
							{
							setState(150);
							match(COMMA);
							setState(151);
							match(T__15);
							}
						}

						{
						setState(154);
						match(Identifier);
						setState(155);
						match(T__9);
						setState(156);
						match(Identifier);
						}
						}
						} 
					}
					setState(161);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,16,_ctx);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(162);
				match(T__15);
				setState(163);
				match(Identifier);
				setState(167);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,17,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(164);
						match(Identifier);
						}
						} 
					}
					setState(169);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,17,_ctx);
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(170);
				match(T__15);
				setState(171);
				match(Identifier);
				setState(172);
				match(T__5);
				setState(173);
				match(T__10);
				setState(174);
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

	@SuppressWarnings("CheckReturnValue")
	public static class Identifiers_listContext extends ParserRuleContext {
		public List<TerminalNode> Identifier() { return getTokens(ByStmtParser.Identifier); }
		public TerminalNode Identifier(int i) {
			return getToken(ByStmtParser.Identifier, i);
		}
		public Identifiers_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_identifiers_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ByStmtListener ) ((ByStmtListener)listener).enterIdentifiers_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ByStmtListener ) ((ByStmtListener)listener).exitIdentifiers_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ByStmtVisitor ) return ((ByStmtVisitor<? extends T>)visitor).visitIdentifiers_list(this);
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
			setState(181); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				setState(181);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,19,_ctx) ) {
				case 1:
					{
					setState(177);
					match(Identifier);
					}
					break;
				case 2:
					{
					setState(178);
					match(Identifier);
					setState(179);
					match(T__9);
					setState(180);
					match(Identifier);
					}
					break;
				}
				}
				setState(183); 
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
		public TerminalNode Identifier() { return getToken(ByStmtParser.Identifier, 0); }
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
		public List<TerminalNode> COMMA() { return getTokens(ByStmtParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(ByStmtParser.COMMA, i);
		}
		public In_var_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_in_var_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ByStmtListener ) ((ByStmtListener)listener).enterIn_var_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ByStmtListener ) ((ByStmtListener)listener).exitIn_var_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ByStmtVisitor ) return ((ByStmtVisitor<? extends T>)visitor).visitIn_var_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final In_var_listContext in_var_list() throws RecognitionException {
		In_var_listContext _localctx = new In_var_listContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_in_var_list);
		int _la;
		try {
			setState(203);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Identifier:
				enterOuterAlt(_localctx, 1);
				{
				setState(185);
				match(Identifier);
				}
				break;
			case T__1:
				enterOuterAlt(_localctx, 2);
				{
				setState(186);
				match(T__1);
				setState(189);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,21,_ctx) ) {
				case 1:
					{
					setState(187);
					literal();
					}
					break;
				case 2:
					{
					setState(188);
					colonInts();
					}
					break;
				}
				setState(198);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMMA) {
					{
					{
					setState(191);
					match(COMMA);
					setState(194);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,22,_ctx) ) {
					case 1:
						{
						setState(192);
						literal();
						}
						break;
					case 2:
						{
						setState(193);
						colonInts();
						}
						break;
					}
					}
					}
					setState(200);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(201);
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

	@SuppressWarnings("CheckReturnValue")
	public static class ColonIntsContext extends ParserRuleContext {
		public List<TerminalNode> INT() { return getTokens(ByStmtParser.INT); }
		public TerminalNode INT(int i) {
			return getToken(ByStmtParser.INT, i);
		}
		public ColonIntsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_colonInts; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ByStmtListener ) ((ByStmtListener)listener).enterColonInts(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ByStmtListener ) ((ByStmtListener)listener).exitColonInts(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ByStmtVisitor ) return ((ByStmtVisitor<? extends T>)visitor).visitColonInts(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ColonIntsContext colonInts() throws RecognitionException {
		ColonIntsContext _localctx = new ColonIntsContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_colonInts);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(205);
			match(INT);
			setState(206);
			match(T__16);
			setState(207);
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
		public TerminalNode INT() { return getToken(ByStmtParser.INT, 0); }
		public TerminalNode FloatingPointLiteral() { return getToken(ByStmtParser.FloatingPointLiteral, 0); }
		public TerminalNode STRINGLITERAL() { return getToken(ByStmtParser.STRINGLITERAL, 0); }
		public TerminalNode DateLiteral() { return getToken(ByStmtParser.DateLiteral, 0); }
		public TerminalNode TimeLiteral() { return getToken(ByStmtParser.TimeLiteral, 0); }
		public TerminalNode DateTimeLiteral() { return getToken(ByStmtParser.DateTimeLiteral, 0); }
		public TerminalNode BitLiteral() { return getToken(ByStmtParser.BitLiteral, 0); }
		public TerminalNode NameLiteral() { return getToken(ByStmtParser.NameLiteral, 0); }
		public TerminalNode HexLiteral() { return getToken(ByStmtParser.HexLiteral, 0); }
		public TerminalNode DOT() { return getToken(ByStmtParser.DOT, 0); }
		public LiteralContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_literal; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ByStmtListener ) ((ByStmtListener)listener).enterLiteral(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ByStmtListener ) ((ByStmtListener)listener).exitLiteral(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ByStmtVisitor ) return ((ByStmtVisitor<? extends T>)visitor).visitLiteral(this);
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
			setState(209);
			_la = _input.LA(1);
			if ( !(((((_la - 212)) & ~0x3f) == 0 && ((1L << (_la - 212)) & 1535L) != 0)) ) {
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
		public TerminalNode Identifier() { return getToken(ByStmtParser.Identifier, 0); }
		public TerminalNode DATE() { return getToken(ByStmtParser.DATE, 0); }
		public TerminalNode ALTER() { return getToken(ByStmtParser.ALTER, 0); }
		public TerminalNode DROP() { return getToken(ByStmtParser.DROP, 0); }
		public List<VariablesContext> variables() {
			return getRuleContexts(VariablesContext.class);
		}
		public VariablesContext variables(int i) {
			return getRuleContext(VariablesContext.class,i);
		}
		public TerminalNode DOT() { return getToken(ByStmtParser.DOT, 0); }
		public VariablesContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variables; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ByStmtListener ) ((ByStmtListener)listener).enterVariables(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ByStmtListener ) ((ByStmtListener)listener).exitVariables(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ByStmtVisitor ) return ((ByStmtVisitor<? extends T>)visitor).visitVariables(this);
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
			setState(216);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Identifier:
				{
				setState(212);
				match(Identifier);
				}
				break;
			case DATE:
				{
				setState(213);
				match(DATE);
				}
				break;
			case ALTER:
				{
				setState(214);
				match(ALTER);
				}
				break;
			case DROP:
				{
				setState(215);
				match(DROP);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(223);
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
					setState(218);
					if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
					setState(219);
					match(DOT);
					setState(220);
					variables(6);
					}
					} 
				}
				setState(225);
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
		"\u0004\u0001\u00e6\u00e3\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001"+
		"\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004"+
		"\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007"+
		"\u0002\b\u0007\b\u0002\t\u0007\t\u0001\u0000\u0005\u0000\u0016\b\u0000"+
		"\n\u0000\f\u0000\u0019\t\u0000\u0001\u0000\u0001\u0000\u0001\u0001\u0001"+
		"\u0001\u0003\u0001\u001f\b\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0003"+
		"\u0001$\b\u0001\u0001\u0001\u0005\u0001\'\b\u0001\n\u0001\f\u0001*\t\u0001"+
		"\u0001\u0001\u0003\u0001-\b\u0001\u0001\u0001\u0003\u00010\b\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0003\u0002?\b\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0003"+
		"\u0002b\b\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0005\u0002r\b\u0002\n\u0002"+
		"\f\u0002u\t\u0002\u0001\u0003\u0001\u0003\u0001\u0003\u0003\u0003z\b\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0003\u0003\u007f\b\u0003\u0005\u0003"+
		"\u0081\b\u0003\n\u0003\f\u0003\u0084\t\u0003\u0001\u0003\u0001\u0003\u0004"+
		"\u0003\u0088\b\u0003\u000b\u0003\f\u0003\u0089\u0001\u0003\u0005\u0003"+
		"\u008d\b\u0003\n\u0003\f\u0003\u0090\t\u0003\u0001\u0004\u0001\u0004\u0001"+
		"\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0003\u0004\u0099"+
		"\b\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0005\u0004\u009e\b\u0004"+
		"\n\u0004\f\u0004\u00a1\t\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0005"+
		"\u0004\u00a6\b\u0004\n\u0004\f\u0004\u00a9\t\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0003\u0004\u00b0\b\u0004\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0004\u0005\u00b6\b\u0005\u000b\u0005"+
		"\f\u0005\u00b7\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0003\u0006"+
		"\u00be\b\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0003\u0006\u00c3\b"+
		"\u0006\u0005\u0006\u00c5\b\u0006\n\u0006\f\u0006\u00c8\t\u0006\u0001\u0006"+
		"\u0001\u0006\u0003\u0006\u00cc\b\u0006\u0001\u0007\u0001\u0007\u0001\u0007"+
		"\u0001\u0007\u0001\b\u0001\b\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0003"+
		"\t\u00d9\b\t\u0001\t\u0001\t\u0001\t\u0005\t\u00de\b\t\n\t\f\t\u00e1\t"+
		"\t\u0001\t\u0000\u0003\u0004\u0006\u0012\n\u0000\u0002\u0004\u0006\b\n"+
		"\f\u000e\u0010\u0012\u0000\b\u0001\u0000\t\n\u0001\u0000\u000b\r\u0001"+
		"\u0000\u000e\u000f\u0001\u0000\u00c1\u00c6\u0001\u0000\u00c8\u00cd\u0001"+
		"\u0000\u00cf\u00d0\u0002\u0000\u00c7\u00c7\u00ce\u00ce\u0002\u0000\u00d4"+
		"\u00dc\u00de\u00de\u0105\u0000\u0017\u0001\u0000\u0000\u0000\u0002\u001c"+
		"\u0001\u0000\u0000\u0000\u0004>\u0001\u0000\u0000\u0000\u0006v\u0001\u0000"+
		"\u0000\u0000\b\u00af\u0001\u0000\u0000\u0000\n\u00b5\u0001\u0000\u0000"+
		"\u0000\f\u00cb\u0001\u0000\u0000\u0000\u000e\u00cd\u0001\u0000\u0000\u0000"+
		"\u0010\u00d1\u0001\u0000\u0000\u0000\u0012\u00d8\u0001\u0000\u0000\u0000"+
		"\u0014\u0016\u0003\u0002\u0001\u0000\u0015\u0014\u0001\u0000\u0000\u0000"+
		"\u0016\u0019\u0001\u0000\u0000\u0000\u0017\u0015\u0001\u0000\u0000\u0000"+
		"\u0017\u0018\u0001\u0000\u0000\u0000\u0018\u001a\u0001\u0000\u0000\u0000"+
		"\u0019\u0017\u0001\u0000\u0000\u0000\u001a\u001b\u0005\u0000\u0000\u0001"+
		"\u001b\u0001\u0001\u0000\u0000\u0000\u001c\u001e\u0005+\u0000\u0000\u001d"+
		"\u001f\u0005y\u0000\u0000\u001e\u001d\u0001\u0000\u0000\u0000\u001e\u001f"+
		"\u0001\u0000\u0000\u0000\u001f \u0001\u0000\u0000\u0000 !\u0005\u00dd"+
		"\u0000\u0000!(\u0001\u0000\u0000\u0000\"$\u0005y\u0000\u0000#\"\u0001"+
		"\u0000\u0000\u0000#$\u0001\u0000\u0000\u0000$%\u0001\u0000\u0000\u0000"+
		"%\'\u0005\u00dd\u0000\u0000&#\u0001\u0000\u0000\u0000\'*\u0001\u0000\u0000"+
		"\u0000(&\u0001\u0000\u0000\u0000()\u0001\u0000\u0000\u0000),\u0001\u0000"+
		"\u0000\u0000*(\u0001\u0000\u0000\u0000+-\u0005x\u0000\u0000,+\u0001\u0000"+
		"\u0000\u0000,-\u0001\u0000\u0000\u0000-/\u0001\u0000\u0000\u0000.0\u0005"+
		"w\u0000\u0000/.\u0001\u0000\u0000\u0000/0\u0001\u0000\u0000\u000001\u0001"+
		"\u0000\u0000\u000012\u0005\u0001\u0000\u00002\u0003\u0001\u0000\u0000"+
		"\u000034\u0006\u0002\uffff\uffff\u00004?\u0003\u0010\b\u00005?\u0005\u00dd"+
		"\u0000\u000067\u0005\u0002\u0000\u000078\u0003\u0004\u0002\u000089\u0005"+
		"\u0003\u0000\u00009?\u0001\u0000\u0000\u0000:;\u0007\u0000\u0000\u0000"+
		";?\u0003\u0004\u0002\f<=\u0005\u00d1\u0000\u0000=?\u0003\u0004\u0002\u000b"+
		">3\u0001\u0000\u0000\u0000>5\u0001\u0000\u0000\u0000>6\u0001\u0000\u0000"+
		"\u0000>:\u0001\u0000\u0000\u0000><\u0001\u0000\u0000\u0000?s\u0001\u0000"+
		"\u0000\u0000@A\n\r\u0000\u0000AB\u0005\b\u0000\u0000Br\u0003\u0004\u0002"+
		"\rCD\n\n\u0000\u0000DE\u0005\u00d2\u0000\u0000Er\u0003\u0004\u0002\u000b"+
		"FG\n\t\u0000\u0000GH\u0005\u00d3\u0000\u0000Hr\u0003\u0004\u0002\nIJ\n"+
		"\b\u0000\u0000JK\u0007\u0001\u0000\u0000Kr\u0003\u0004\u0002\tLM\n\u0007"+
		"\u0000\u0000MN\u0007\u0000\u0000\u0000Nr\u0003\u0004\u0002\bOP\n\u0006"+
		"\u0000\u0000PQ\u0007\u0002\u0000\u0000Qr\u0003\u0004\u0002\u0007RS\n\u0005"+
		"\u0000\u0000ST\u0007\u0003\u0000\u0000Tr\u0003\u0004\u0002\u0006UV\n\u0004"+
		"\u0000\u0000VW\u0007\u0004\u0000\u0000Wr\u0003\u0004\u0002\u0005XY\n\u0002"+
		"\u0000\u0000YZ\u0007\u0005\u0000\u0000Zr\u0003\u0004\u0002\u0003[\\\n"+
		"\u0001\u0000\u0000\\]\u0005\u00e0\u0000\u0000]r\u0003\u0004\u0002\u0001"+
		"^_\n\u0010\u0000\u0000_a\u0005\u0002\u0000\u0000`b\u0003\u0006\u0003\u0000"+
		"a`\u0001\u0000\u0000\u0000ab\u0001\u0000\u0000\u0000bc\u0001\u0000\u0000"+
		"\u0000cr\u0005\u0003\u0000\u0000de\n\u000f\u0000\u0000ef\u0005\u0004\u0000"+
		"\u0000fg\u0003\u0004\u0002\u0000gh\u0005\u0005\u0000\u0000hr\u0001\u0000"+
		"\u0000\u0000ij\n\u000e\u0000\u0000jk\u0005\u0006\u0000\u0000kl\u0003\u0004"+
		"\u0002\u0000lm\u0005\u0007\u0000\u0000mr\u0001\u0000\u0000\u0000no\n\u0003"+
		"\u0000\u0000op\u0007\u0006\u0000\u0000pr\u0003\f\u0006\u0000q@\u0001\u0000"+
		"\u0000\u0000qC\u0001\u0000\u0000\u0000qF\u0001\u0000\u0000\u0000qI\u0001"+
		"\u0000\u0000\u0000qL\u0001\u0000\u0000\u0000qO\u0001\u0000\u0000\u0000"+
		"qR\u0001\u0000\u0000\u0000qU\u0001\u0000\u0000\u0000qX\u0001\u0000\u0000"+
		"\u0000q[\u0001\u0000\u0000\u0000q^\u0001\u0000\u0000\u0000qd\u0001\u0000"+
		"\u0000\u0000qi\u0001\u0000\u0000\u0000qn\u0001\u0000\u0000\u0000ru\u0001"+
		"\u0000\u0000\u0000sq\u0001\u0000\u0000\u0000st\u0001\u0000\u0000\u0000"+
		"t\u0005\u0001\u0000\u0000\u0000us\u0001\u0000\u0000\u0000vy\u0006\u0003"+
		"\uffff\uffff\u0000wz\u0003\u0004\u0002\u0000xz\u0003\b\u0004\u0000yw\u0001"+
		"\u0000\u0000\u0000yx\u0001\u0000\u0000\u0000z\u0082\u0001\u0000\u0000"+
		"\u0000{~\u0005\u00e1\u0000\u0000|\u007f\u0003\u0004\u0002\u0000}\u007f"+
		"\u0003\b\u0004\u0000~|\u0001\u0000\u0000\u0000~}\u0001\u0000\u0000\u0000"+
		"\u007f\u0081\u0001\u0000\u0000\u0000\u0080{\u0001\u0000\u0000\u0000\u0081"+
		"\u0084\u0001\u0000\u0000\u0000\u0082\u0080\u0001\u0000\u0000\u0000\u0082"+
		"\u0083\u0001\u0000\u0000\u0000\u0083\u008e\u0001\u0000\u0000\u0000\u0084"+
		"\u0082\u0001\u0000\u0000\u0000\u0085\u0087\n\u0001\u0000\u0000\u0086\u0088"+
		"\u0005\u00e1\u0000\u0000\u0087\u0086\u0001\u0000\u0000\u0000\u0088\u0089"+
		"\u0001\u0000\u0000\u0000\u0089\u0087\u0001\u0000\u0000\u0000\u0089\u008a"+
		"\u0001\u0000\u0000\u0000\u008a\u008b\u0001\u0000\u0000\u0000\u008b\u008d"+
		"\u0003\u0006\u0003\u0002\u008c\u0085\u0001\u0000\u0000\u0000\u008d\u0090"+
		"\u0001\u0000\u0000\u0000\u008e\u008c\u0001\u0000\u0000\u0000\u008e\u008f"+
		"\u0001\u0000\u0000\u0000\u008f\u0007\u0001\u0000\u0000\u0000\u0090\u008e"+
		"\u0001\u0000\u0000\u0000\u0091\u0092\u0005\u0010\u0000\u0000\u0092\u0093"+
		"\u0005\u00dd\u0000\u0000\u0093\u0094\u0005\n\u0000\u0000\u0094\u0095\u0005"+
		"\u00dd\u0000\u0000\u0095\u009f\u0001\u0000\u0000\u0000\u0096\u0097\u0005"+
		"\u00e1\u0000\u0000\u0097\u0099\u0005\u0010\u0000\u0000\u0098\u0096\u0001"+
		"\u0000\u0000\u0000\u0098\u0099\u0001\u0000\u0000\u0000\u0099\u009a\u0001"+
		"\u0000\u0000\u0000\u009a\u009b\u0005\u00dd\u0000\u0000\u009b\u009c\u0005"+
		"\n\u0000\u0000\u009c\u009e\u0005\u00dd\u0000\u0000\u009d\u0098\u0001\u0000"+
		"\u0000\u0000\u009e\u00a1\u0001\u0000\u0000\u0000\u009f\u009d\u0001\u0000"+
		"\u0000\u0000\u009f\u00a0\u0001\u0000\u0000\u0000\u00a0\u00b0\u0001\u0000"+
		"\u0000\u0000\u00a1\u009f\u0001\u0000\u0000\u0000\u00a2\u00a3\u0005\u0010"+
		"\u0000\u0000\u00a3\u00a7\u0005\u00dd\u0000\u0000\u00a4\u00a6\u0005\u00dd"+
		"\u0000\u0000\u00a5\u00a4\u0001\u0000\u0000\u0000\u00a6\u00a9\u0001\u0000"+
		"\u0000\u0000\u00a7\u00a5\u0001\u0000\u0000\u0000\u00a7\u00a8\u0001\u0000"+
		"\u0000\u0000\u00a8\u00b0\u0001\u0000\u0000\u0000\u00a9\u00a7\u0001\u0000"+
		"\u0000\u0000\u00aa\u00ab\u0005\u0010\u0000\u0000\u00ab\u00ac\u0005\u00dd"+
		"\u0000\u0000\u00ac\u00ad\u0005\u0006\u0000\u0000\u00ad\u00ae\u0005\u000b"+
		"\u0000\u0000\u00ae\u00b0\u0005\u0007\u0000\u0000\u00af\u0091\u0001\u0000"+
		"\u0000\u0000\u00af\u00a2\u0001\u0000\u0000\u0000\u00af\u00aa\u0001\u0000"+
		"\u0000\u0000\u00b0\t\u0001\u0000\u0000\u0000\u00b1\u00b6\u0005\u00dd\u0000"+
		"\u0000\u00b2\u00b3\u0005\u00dd\u0000\u0000\u00b3\u00b4\u0005\n\u0000\u0000"+
		"\u00b4\u00b6\u0005\u00dd\u0000\u0000\u00b5\u00b1\u0001\u0000\u0000\u0000"+
		"\u00b5\u00b2\u0001\u0000\u0000\u0000\u00b6\u00b7\u0001\u0000\u0000\u0000"+
		"\u00b7\u00b5\u0001\u0000\u0000\u0000\u00b7\u00b8\u0001\u0000\u0000\u0000"+
		"\u00b8\u000b\u0001\u0000\u0000\u0000\u00b9\u00cc\u0005\u00dd\u0000\u0000"+
		"\u00ba\u00bd\u0005\u0002\u0000\u0000\u00bb\u00be\u0003\u0010\b\u0000\u00bc"+
		"\u00be\u0003\u000e\u0007\u0000\u00bd\u00bb\u0001\u0000\u0000\u0000\u00bd"+
		"\u00bc\u0001\u0000\u0000\u0000\u00be\u00c6\u0001\u0000\u0000\u0000\u00bf"+
		"\u00c2\u0005\u00e1\u0000\u0000\u00c0\u00c3\u0003\u0010\b\u0000\u00c1\u00c3"+
		"\u0003\u000e\u0007\u0000\u00c2\u00c0\u0001\u0000\u0000\u0000\u00c2\u00c1"+
		"\u0001\u0000\u0000\u0000\u00c3\u00c5\u0001\u0000\u0000\u0000\u00c4\u00bf"+
		"\u0001\u0000\u0000\u0000\u00c5\u00c8\u0001\u0000\u0000\u0000\u00c6\u00c4"+
		"\u0001\u0000\u0000\u0000\u00c6\u00c7\u0001\u0000\u0000\u0000\u00c7\u00c9"+
		"\u0001\u0000\u0000\u0000\u00c8\u00c6\u0001\u0000\u0000\u0000\u00c9\u00ca"+
		"\u0005\u0003\u0000\u0000\u00ca\u00cc\u0001\u0000\u0000\u0000\u00cb\u00b9"+
		"\u0001\u0000\u0000\u0000\u00cb\u00ba\u0001\u0000\u0000\u0000\u00cc\r\u0001"+
		"\u0000\u0000\u0000\u00cd\u00ce\u0005\u00db\u0000\u0000\u00ce\u00cf\u0005"+
		"\u0011\u0000\u0000\u00cf\u00d0\u0005\u00db\u0000\u0000\u00d0\u000f\u0001"+
		"\u0000\u0000\u0000\u00d1\u00d2\u0007\u0007\u0000\u0000\u00d2\u0011\u0001"+
		"\u0000\u0000\u0000\u00d3\u00d4\u0006\t\uffff\uffff\u0000\u00d4\u00d9\u0005"+
		"\u00dd\u0000\u0000\u00d5\u00d9\u0005\u00a4\u0000\u0000\u00d6\u00d9\u0005"+
		"\u008c\u0000\u0000\u00d7\u00d9\u0005\u00a9\u0000\u0000\u00d8\u00d3\u0001"+
		"\u0000\u0000\u0000\u00d8\u00d5\u0001\u0000\u0000\u0000\u00d8\u00d6\u0001"+
		"\u0000\u0000\u0000\u00d8\u00d7\u0001\u0000\u0000\u0000\u00d9\u00df\u0001"+
		"\u0000\u0000\u0000\u00da\u00db\n\u0005\u0000\u0000\u00db\u00dc\u0005\u00de"+
		"\u0000\u0000\u00dc\u00de\u0003\u0012\t\u0006\u00dd\u00da\u0001\u0000\u0000"+
		"\u0000\u00de\u00e1\u0001\u0000\u0000\u0000\u00df\u00dd\u0001\u0000\u0000"+
		"\u0000\u00df\u00e0\u0001\u0000\u0000\u0000\u00e0\u0013\u0001\u0000\u0000"+
		"\u0000\u00e1\u00df\u0001\u0000\u0000\u0000\u001b\u0017\u001e#(,/>aqsy"+
		"~\u0082\u0089\u008e\u0098\u009f\u00a7\u00af\u00b5\u00b7\u00bd\u00c2\u00c6"+
		"\u00cb\u00d8\u00df";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}