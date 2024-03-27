// Generated from ProcStmt.g4 by ANTLR 4.8
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class ProcStmtParser extends Parser {
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
		COMMA=225, LBracket=226, RBracket=227, WS=228, COMMENT=229, LINE_COMMENT=230, 
		SURVEYSELCT=231;
	public static final int
		RULE_proc_main = 0, RULE_proc_stmt = 1, RULE_proc_name = 2, RULE_expression = 3, 
		RULE_expressionList = 4, RULE_of_var_list = 5, RULE_identifiers_list = 6, 
		RULE_in_var_list = 7, RULE_colonInts = 8, RULE_literal = 9, RULE_variables = 10;
	private static String[] makeRuleNames() {
		return new String[] {
			"proc_main", "proc_stmt", "proc_name", "expression", "expressionList", 
			"of_var_list", "identifiers_list", "in_var_list", "colonInts", "literal", 
			"variables"
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
			"WS", "COMMENT", "LINE_COMMENT", "SURVEYSELCT"
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
	public String getGrammarFileName() { return "ProcStmt.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public ProcStmtParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class Proc_mainContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(ProcStmtParser.EOF, 0); }
		public List<Proc_stmtContext> proc_stmt() {
			return getRuleContexts(Proc_stmtContext.class);
		}
		public Proc_stmtContext proc_stmt(int i) {
			return getRuleContext(Proc_stmtContext.class,i);
		}
		public Proc_mainContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_proc_main; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ProcStmtListener ) ((ProcStmtListener)listener).enterProc_main(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ProcStmtListener ) ((ProcStmtListener)listener).exitProc_main(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ProcStmtVisitor ) return ((ProcStmtVisitor<? extends T>)visitor).visitProc_main(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Proc_mainContext proc_main() throws RecognitionException {
		Proc_mainContext _localctx = new Proc_mainContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_proc_main);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(25);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==PROC) {
				{
				{
				setState(22);
				proc_stmt();
				}
				}
				setState(27);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(28);
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

	public static class Proc_stmtContext extends ParserRuleContext {
		public TerminalNode PROC() { return getToken(ProcStmtParser.PROC, 0); }
		public Proc_nameContext proc_name() {
			return getRuleContext(Proc_nameContext.class,0);
		}
		public Proc_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_proc_stmt; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ProcStmtListener ) ((ProcStmtListener)listener).enterProc_stmt(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ProcStmtListener ) ((ProcStmtListener)listener).exitProc_stmt(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ProcStmtVisitor ) return ((ProcStmtVisitor<? extends T>)visitor).visitProc_stmt(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Proc_stmtContext proc_stmt() throws RecognitionException {
		Proc_stmtContext _localctx = new Proc_stmtContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_proc_stmt);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(30);
			match(PROC);
			setState(31);
			proc_name();
			setState(35);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,1,_ctx);
			while ( _alt!=1 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1+1 ) {
					{
					{
					setState(32);
					_la = _input.LA(1);
					if ( _la <= 0 || (_la==T__0) ) {
					_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					}
					} 
				}
				setState(37);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,1,_ctx);
			}
			setState(38);
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

	public static class Proc_nameContext extends ParserRuleContext {
		public TerminalNode ANOVA() { return getToken(ProcStmtParser.ANOVA, 0); }
		public TerminalNode CORR() { return getToken(ProcStmtParser.CORR, 0); }
		public TerminalNode MEANS() { return getToken(ProcStmtParser.MEANS, 0); }
		public TerminalNode REG() { return getToken(ProcStmtParser.REG, 0); }
		public TerminalNode SGPLOT() { return getToken(ProcStmtParser.SGPLOT, 0); }
		public TerminalNode PRINT() { return getToken(ProcStmtParser.PRINT, 0); }
		public TerminalNode GLM() { return getToken(ProcStmtParser.GLM, 0); }
		public TerminalNode FREQ() { return getToken(ProcStmtParser.FREQ, 0); }
		public TerminalNode SQL() { return getToken(ProcStmtParser.SQL, 0); }
		public TerminalNode UNIVARIATE() { return getToken(ProcStmtParser.UNIVARIATE, 0); }
		public TerminalNode NPAR1WAY() { return getToken(ProcStmtParser.NPAR1WAY, 0); }
		public TerminalNode IMPORT() { return getToken(ProcStmtParser.IMPORT, 0); }
		public TerminalNode SORT() { return getToken(ProcStmtParser.SORT, 0); }
		public TerminalNode DATASETS() { return getToken(ProcStmtParser.DATASETS, 0); }
		public TerminalNode TABULATE() { return getToken(ProcStmtParser.TABULATE, 0); }
		public TerminalNode RANK() { return getToken(ProcStmtParser.RANK, 0); }
		public TerminalNode CHART() { return getToken(ProcStmtParser.CHART, 0); }
		public TerminalNode LOGISTIC() { return getToken(ProcStmtParser.LOGISTIC, 0); }
		public TerminalNode SURVEYSELCT() { return getToken(ProcStmtParser.SURVEYSELCT, 0); }
		public Proc_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_proc_name; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ProcStmtListener ) ((ProcStmtListener)listener).enterProc_name(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ProcStmtListener ) ((ProcStmtListener)listener).exitProc_name(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ProcStmtVisitor ) return ((ProcStmtVisitor<? extends T>)visitor).visitProc_name(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Proc_nameContext proc_name() throws RecognitionException {
		Proc_nameContext _localctx = new Proc_nameContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_proc_name);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(40);
			_la = _input.LA(1);
			if ( !(((((_la - 171)) & ~0x3f) == 0 && ((1L << (_la - 171)) & ((1L << (ANOVA - 171)) | (1L << (MEANS - 171)) | (1L << (REG - 171)) | (1L << (CORR - 171)) | (1L << (SGPLOT - 171)) | (1L << (PRINT - 171)) | (1L << (GLM - 171)) | (1L << (FREQ - 171)) | (1L << (SQL - 171)) | (1L << (UNIVARIATE - 171)) | (1L << (NPAR1WAY - 171)) | (1L << (IMPORT - 171)) | (1L << (SORT - 171)) | (1L << (DATASETS - 171)) | (1L << (TABULATE - 171)) | (1L << (RANK - 171)) | (1L << (CHART - 171)) | (1L << (LOGISTIC - 171)) | (1L << (SURVEYSELCT - 171)))) != 0)) ) {
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
		public TerminalNode Identifier() { return getToken(ProcStmtParser.Identifier, 0); }
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode NOT() { return getToken(ProcStmtParser.NOT, 0); }
		public TerminalNode MIN() { return getToken(ProcStmtParser.MIN, 0); }
		public TerminalNode MAX() { return getToken(ProcStmtParser.MAX, 0); }
		public TerminalNode EQ() { return getToken(ProcStmtParser.EQ, 0); }
		public TerminalNode NE() { return getToken(ProcStmtParser.NE, 0); }
		public TerminalNode GT() { return getToken(ProcStmtParser.GT, 0); }
		public TerminalNode LT() { return getToken(ProcStmtParser.LT, 0); }
		public TerminalNode GE() { return getToken(ProcStmtParser.GE, 0); }
		public TerminalNode LE() { return getToken(ProcStmtParser.LE, 0); }
		public TerminalNode EQC() { return getToken(ProcStmtParser.EQC, 0); }
		public TerminalNode NEC() { return getToken(ProcStmtParser.NEC, 0); }
		public TerminalNode GTC() { return getToken(ProcStmtParser.GTC, 0); }
		public TerminalNode LTC() { return getToken(ProcStmtParser.LTC, 0); }
		public TerminalNode GEC() { return getToken(ProcStmtParser.GEC, 0); }
		public TerminalNode LEC() { return getToken(ProcStmtParser.LEC, 0); }
		public TerminalNode AND() { return getToken(ProcStmtParser.AND, 0); }
		public TerminalNode OR() { return getToken(ProcStmtParser.OR, 0); }
		public TerminalNode EQUAL() { return getToken(ProcStmtParser.EQUAL, 0); }
		public ExpressionListContext expressionList() {
			return getRuleContext(ExpressionListContext.class,0);
		}
		public In_var_listContext in_var_list() {
			return getRuleContext(In_var_listContext.class,0);
		}
		public TerminalNode IN() { return getToken(ProcStmtParser.IN, 0); }
		public TerminalNode INColon() { return getToken(ProcStmtParser.INColon, 0); }
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ProcStmtListener ) ((ProcStmtListener)listener).enterExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ProcStmtListener ) ((ProcStmtListener)listener).exitExpression(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ProcStmtVisitor ) return ((ProcStmtVisitor<? extends T>)visitor).visitExpression(this);
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
		int _startState = 6;
		enterRecursionRule(_localctx, 6, RULE_expression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(53);
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
				setState(43);
				literal();
				}
				break;
			case Identifier:
				{
				setState(44);
				match(Identifier);
				}
				break;
			case T__1:
				{
				setState(45);
				match(T__1);
				setState(46);
				expression(0);
				setState(47);
				match(T__2);
				}
				break;
			case T__8:
			case T__9:
				{
				setState(49);
				_la = _input.LA(1);
				if ( !(_la==T__8 || _la==T__9) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(50);
				expression(12);
				}
				break;
			case NOT:
				{
				setState(51);
				match(NOT);
				setState(52);
				expression(11);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(106);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,5,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(104);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
					case 1:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(55);
						if (!(precpred(_ctx, 13))) throw new FailedPredicateException(this, "precpred(_ctx, 13)");
						setState(56);
						match(T__7);
						setState(57);
						expression(13);
						}
						break;
					case 2:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(58);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(59);
						match(MIN);
						setState(60);
						expression(11);
						}
						break;
					case 3:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(61);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(62);
						match(MAX);
						setState(63);
						expression(10);
						}
						break;
					case 4:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(64);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(65);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__10) | (1L << T__11) | (1L << T__12))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(66);
						expression(9);
						}
						break;
					case 5:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(67);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(68);
						_la = _input.LA(1);
						if ( !(_la==T__8 || _la==T__9) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(69);
						expression(8);
						}
						break;
					case 6:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(70);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(71);
						_la = _input.LA(1);
						if ( !(_la==T__13 || _la==T__14) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(72);
						expression(7);
						}
						break;
					case 7:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(73);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(74);
						_la = _input.LA(1);
						if ( !(((((_la - 193)) & ~0x3f) == 0 && ((1L << (_la - 193)) & ((1L << (EQ - 193)) | (1L << (NE - 193)) | (1L << (GT - 193)) | (1L << (LT - 193)) | (1L << (GE - 193)) | (1L << (LE - 193)))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(75);
						expression(6);
						}
						break;
					case 8:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(76);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(77);
						_la = _input.LA(1);
						if ( !(((((_la - 200)) & ~0x3f) == 0 && ((1L << (_la - 200)) & ((1L << (EQC - 200)) | (1L << (NEC - 200)) | (1L << (GTC - 200)) | (1L << (LTC - 200)) | (1L << (GEC - 200)) | (1L << (LEC - 200)))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(78);
						expression(5);
						}
						break;
					case 9:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(79);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(80);
						_la = _input.LA(1);
						if ( !(_la==AND || _la==OR) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(81);
						expression(3);
						}
						break;
					case 10:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(82);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(83);
						match(EQUAL);
						setState(84);
						expression(1);
						}
						break;
					case 11:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(85);
						if (!(precpred(_ctx, 16))) throw new FailedPredicateException(this, "precpred(_ctx, 16)");
						setState(86);
						match(T__1);
						setState(88);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__1) | (1L << T__8) | (1L << T__9) | (1L << T__15))) != 0) || ((((_la - 209)) & ~0x3f) == 0 && ((1L << (_la - 209)) & ((1L << (NOT - 209)) | (1L << (DateLiteral - 209)) | (1L << (TimeLiteral - 209)) | (1L << (DateTimeLiteral - 209)) | (1L << (BitLiteral - 209)) | (1L << (NameLiteral - 209)) | (1L << (HexLiteral - 209)) | (1L << (STRINGLITERAL - 209)) | (1L << (INT - 209)) | (1L << (FloatingPointLiteral - 209)) | (1L << (Identifier - 209)) | (1L << (DOT - 209)))) != 0)) {
							{
							setState(87);
							expressionList(0);
							}
						}

						setState(90);
						match(T__2);
						}
						break;
					case 12:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(91);
						if (!(precpred(_ctx, 15))) throw new FailedPredicateException(this, "precpred(_ctx, 15)");
						setState(92);
						match(T__3);
						setState(93);
						expression(0);
						setState(94);
						match(T__4);
						}
						break;
					case 13:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(96);
						if (!(precpred(_ctx, 14))) throw new FailedPredicateException(this, "precpred(_ctx, 14)");
						setState(97);
						match(T__5);
						setState(98);
						expression(0);
						setState(99);
						match(T__6);
						}
						break;
					case 14:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(101);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(102);
						_la = _input.LA(1);
						if ( !(_la==IN || _la==INColon) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(103);
						in_var_list();
						}
						break;
					}
					} 
				}
				setState(108);
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
		public List<TerminalNode> COMMA() { return getTokens(ProcStmtParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(ProcStmtParser.COMMA, i);
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
			if ( listener instanceof ProcStmtListener ) ((ProcStmtListener)listener).enterExpressionList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ProcStmtListener ) ((ProcStmtListener)listener).exitExpressionList(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ProcStmtVisitor ) return ((ProcStmtVisitor<? extends T>)visitor).visitExpressionList(this);
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
		int _startState = 8;
		enterRecursionRule(_localctx, 8, RULE_expressionList, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(112);
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
				setState(110);
				expression(0);
				}
				break;
			case T__15:
				{
				setState(111);
				of_var_list();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(121);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(114);
					match(COMMA);
					setState(117);
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
						setState(115);
						expression(0);
						}
						break;
					case T__15:
						{
						setState(116);
						of_var_list();
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					}
					} 
				}
				setState(123);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
			}
			}
			_ctx.stop = _input.LT(-1);
			setState(133);
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
					setState(124);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(126); 
					_errHandler.sync(this);
					_la = _input.LA(1);
					do {
						{
						{
						setState(125);
						match(COMMA);
						}
						}
						setState(128); 
						_errHandler.sync(this);
						_la = _input.LA(1);
					} while ( _la==COMMA );
					setState(130);
					expressionList(2);
					}
					} 
				}
				setState(135);
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
		public List<TerminalNode> Identifier() { return getTokens(ProcStmtParser.Identifier); }
		public TerminalNode Identifier(int i) {
			return getToken(ProcStmtParser.Identifier, i);
		}
		public List<TerminalNode> COMMA() { return getTokens(ProcStmtParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(ProcStmtParser.COMMA, i);
		}
		public Of_var_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_of_var_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ProcStmtListener ) ((ProcStmtListener)listener).enterOf_var_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ProcStmtListener ) ((ProcStmtListener)listener).exitOf_var_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ProcStmtVisitor ) return ((ProcStmtVisitor<? extends T>)visitor).visitOf_var_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Of_var_listContext of_var_list() throws RecognitionException {
		Of_var_listContext _localctx = new Of_var_listContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_of_var_list);
		int _la;
		try {
			int _alt;
			setState(166);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(136);
				match(T__15);
				{
				setState(137);
				match(Identifier);
				setState(138);
				match(T__9);
				setState(139);
				match(Identifier);
				}
				setState(150);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(143);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if (_la==COMMA) {
							{
							setState(141);
							match(COMMA);
							setState(142);
							match(T__15);
							}
						}

						{
						setState(145);
						match(Identifier);
						setState(146);
						match(T__9);
						setState(147);
						match(Identifier);
						}
						}
						} 
					}
					setState(152);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(153);
				match(T__15);
				setState(154);
				match(Identifier);
				setState(158);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(155);
						match(Identifier);
						}
						} 
					}
					setState(160);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(161);
				match(T__15);
				setState(162);
				match(Identifier);
				setState(163);
				match(T__5);
				setState(164);
				match(T__10);
				setState(165);
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
		public List<TerminalNode> Identifier() { return getTokens(ProcStmtParser.Identifier); }
		public TerminalNode Identifier(int i) {
			return getToken(ProcStmtParser.Identifier, i);
		}
		public Identifiers_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_identifiers_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ProcStmtListener ) ((ProcStmtListener)listener).enterIdentifiers_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ProcStmtListener ) ((ProcStmtListener)listener).exitIdentifiers_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ProcStmtVisitor ) return ((ProcStmtVisitor<? extends T>)visitor).visitIdentifiers_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Identifiers_listContext identifiers_list() throws RecognitionException {
		Identifiers_listContext _localctx = new Identifiers_listContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_identifiers_list);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(172); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				setState(172);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
				case 1:
					{
					setState(168);
					match(Identifier);
					}
					break;
				case 2:
					{
					setState(169);
					match(Identifier);
					setState(170);
					match(T__9);
					setState(171);
					match(Identifier);
					}
					break;
				}
				}
				setState(174); 
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
		public TerminalNode Identifier() { return getToken(ProcStmtParser.Identifier, 0); }
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
		public List<TerminalNode> COMMA() { return getTokens(ProcStmtParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(ProcStmtParser.COMMA, i);
		}
		public In_var_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_in_var_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ProcStmtListener ) ((ProcStmtListener)listener).enterIn_var_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ProcStmtListener ) ((ProcStmtListener)listener).exitIn_var_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ProcStmtVisitor ) return ((ProcStmtVisitor<? extends T>)visitor).visitIn_var_list(this);
			else return visitor.visitChildren(this);
		}
	}

	public final In_var_listContext in_var_list() throws RecognitionException {
		In_var_listContext _localctx = new In_var_listContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_in_var_list);
		int _la;
		try {
			setState(194);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Identifier:
				enterOuterAlt(_localctx, 1);
				{
				setState(176);
				match(Identifier);
				}
				break;
			case T__1:
				enterOuterAlt(_localctx, 2);
				{
				setState(177);
				match(T__1);
				setState(180);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
				case 1:
					{
					setState(178);
					literal();
					}
					break;
				case 2:
					{
					setState(179);
					colonInts();
					}
					break;
				}
				setState(189);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMMA) {
					{
					{
					setState(182);
					match(COMMA);
					setState(185);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
					case 1:
						{
						setState(183);
						literal();
						}
						break;
					case 2:
						{
						setState(184);
						colonInts();
						}
						break;
					}
					}
					}
					setState(191);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(192);
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
		public List<TerminalNode> INT() { return getTokens(ProcStmtParser.INT); }
		public TerminalNode INT(int i) {
			return getToken(ProcStmtParser.INT, i);
		}
		public ColonIntsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_colonInts; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ProcStmtListener ) ((ProcStmtListener)listener).enterColonInts(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ProcStmtListener ) ((ProcStmtListener)listener).exitColonInts(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ProcStmtVisitor ) return ((ProcStmtVisitor<? extends T>)visitor).visitColonInts(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ColonIntsContext colonInts() throws RecognitionException {
		ColonIntsContext _localctx = new ColonIntsContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_colonInts);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(196);
			match(INT);
			setState(197);
			match(T__16);
			setState(198);
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
		public TerminalNode INT() { return getToken(ProcStmtParser.INT, 0); }
		public TerminalNode FloatingPointLiteral() { return getToken(ProcStmtParser.FloatingPointLiteral, 0); }
		public TerminalNode STRINGLITERAL() { return getToken(ProcStmtParser.STRINGLITERAL, 0); }
		public TerminalNode DateLiteral() { return getToken(ProcStmtParser.DateLiteral, 0); }
		public TerminalNode TimeLiteral() { return getToken(ProcStmtParser.TimeLiteral, 0); }
		public TerminalNode DateTimeLiteral() { return getToken(ProcStmtParser.DateTimeLiteral, 0); }
		public TerminalNode BitLiteral() { return getToken(ProcStmtParser.BitLiteral, 0); }
		public TerminalNode NameLiteral() { return getToken(ProcStmtParser.NameLiteral, 0); }
		public TerminalNode HexLiteral() { return getToken(ProcStmtParser.HexLiteral, 0); }
		public TerminalNode DOT() { return getToken(ProcStmtParser.DOT, 0); }
		public LiteralContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_literal; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ProcStmtListener ) ((ProcStmtListener)listener).enterLiteral(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ProcStmtListener ) ((ProcStmtListener)listener).exitLiteral(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ProcStmtVisitor ) return ((ProcStmtVisitor<? extends T>)visitor).visitLiteral(this);
			else return visitor.visitChildren(this);
		}
	}

	public final LiteralContext literal() throws RecognitionException {
		LiteralContext _localctx = new LiteralContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_literal);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(200);
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
		public TerminalNode Identifier() { return getToken(ProcStmtParser.Identifier, 0); }
		public TerminalNode DATE() { return getToken(ProcStmtParser.DATE, 0); }
		public TerminalNode ALTER() { return getToken(ProcStmtParser.ALTER, 0); }
		public TerminalNode DROP() { return getToken(ProcStmtParser.DROP, 0); }
		public List<VariablesContext> variables() {
			return getRuleContexts(VariablesContext.class);
		}
		public VariablesContext variables(int i) {
			return getRuleContext(VariablesContext.class,i);
		}
		public TerminalNode DOT() { return getToken(ProcStmtParser.DOT, 0); }
		public VariablesContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variables; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof ProcStmtListener ) ((ProcStmtListener)listener).enterVariables(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof ProcStmtListener ) ((ProcStmtListener)listener).exitVariables(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof ProcStmtVisitor ) return ((ProcStmtVisitor<? extends T>)visitor).visitVariables(this);
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
		int _startState = 20;
		enterRecursionRule(_localctx, 20, RULE_variables, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(207);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Identifier:
				{
				setState(203);
				match(Identifier);
				}
				break;
			case DATE:
				{
				setState(204);
				match(DATE);
				}
				break;
			case ALTER:
				{
				setState(205);
				match(ALTER);
				}
				break;
			case DROP:
				{
				setState(206);
				match(DROP);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(214);
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
					setState(209);
					if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
					setState(210);
					match(DOT);
					setState(211);
					variables(6);
					}
					} 
				}
				setState(216);
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
		case 3:
			return expression_sempred((ExpressionContext)_localctx, predIndex);
		case 4:
			return expressionList_sempred((ExpressionListContext)_localctx, predIndex);
		case 10:
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\u00e9\u00dc\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\3\2\7\2\32\n\2\f\2\16\2\35\13\2\3\2\3\2\3\3\3\3\3\3\7\3"+
		"$\n\3\f\3\16\3\'\13\3\3\3\3\3\3\4\3\4\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5"+
		"\3\5\3\5\3\5\5\58\n\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5"+
		"\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3"+
		"\5\3\5\3\5\3\5\5\5[\n\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3"+
		"\5\3\5\3\5\7\5k\n\5\f\5\16\5n\13\5\3\6\3\6\3\6\5\6s\n\6\3\6\3\6\3\6\5"+
		"\6x\n\6\7\6z\n\6\f\6\16\6}\13\6\3\6\3\6\6\6\u0081\n\6\r\6\16\6\u0082\3"+
		"\6\7\6\u0086\n\6\f\6\16\6\u0089\13\6\3\7\3\7\3\7\3\7\3\7\3\7\3\7\5\7\u0092"+
		"\n\7\3\7\3\7\3\7\7\7\u0097\n\7\f\7\16\7\u009a\13\7\3\7\3\7\3\7\7\7\u009f"+
		"\n\7\f\7\16\7\u00a2\13\7\3\7\3\7\3\7\3\7\3\7\5\7\u00a9\n\7\3\b\3\b\3\b"+
		"\3\b\6\b\u00af\n\b\r\b\16\b\u00b0\3\t\3\t\3\t\3\t\5\t\u00b7\n\t\3\t\3"+
		"\t\3\t\5\t\u00bc\n\t\7\t\u00be\n\t\f\t\16\t\u00c1\13\t\3\t\3\t\5\t\u00c5"+
		"\n\t\3\n\3\n\3\n\3\n\3\13\3\13\3\f\3\f\3\f\3\f\3\f\5\f\u00d2\n\f\3\f\3"+
		"\f\3\f\7\f\u00d7\n\f\f\f\16\f\u00da\13\f\3\f\3%\5\b\n\26\r\2\4\6\b\n\f"+
		"\16\20\22\24\26\2\f\3\2\3\3\5\2\u00ad\u00b2\u00b4\u00bf\u00e9\u00e9\3"+
		"\2\13\f\3\2\r\17\3\2\20\21\3\2\u00c3\u00c8\3\2\u00ca\u00cf\3\2\u00d1\u00d2"+
		"\4\2\u00c9\u00c9\u00d0\u00d0\4\2\u00d6\u00de\u00e0\u00e0\2\u00f9\2\33"+
		"\3\2\2\2\4 \3\2\2\2\6*\3\2\2\2\b\67\3\2\2\2\no\3\2\2\2\f\u00a8\3\2\2\2"+
		"\16\u00ae\3\2\2\2\20\u00c4\3\2\2\2\22\u00c6\3\2\2\2\24\u00ca\3\2\2\2\26"+
		"\u00d1\3\2\2\2\30\32\5\4\3\2\31\30\3\2\2\2\32\35\3\2\2\2\33\31\3\2\2\2"+
		"\33\34\3\2\2\2\34\36\3\2\2\2\35\33\3\2\2\2\36\37\7\2\2\3\37\3\3\2\2\2"+
		" !\7\u00ac\2\2!%\5\6\4\2\"$\n\2\2\2#\"\3\2\2\2$\'\3\2\2\2%&\3\2\2\2%#"+
		"\3\2\2\2&(\3\2\2\2\'%\3\2\2\2()\7\3\2\2)\5\3\2\2\2*+\t\3\2\2+\7\3\2\2"+
		"\2,-\b\5\1\2-8\5\24\13\2.8\7\u00df\2\2/\60\7\4\2\2\60\61\5\b\5\2\61\62"+
		"\7\5\2\2\628\3\2\2\2\63\64\t\4\2\2\648\5\b\5\16\65\66\7\u00d3\2\2\668"+
		"\5\b\5\r\67,\3\2\2\2\67.\3\2\2\2\67/\3\2\2\2\67\63\3\2\2\2\67\65\3\2\2"+
		"\28l\3\2\2\29:\f\17\2\2:;\7\n\2\2;k\5\b\5\17<=\f\f\2\2=>\7\u00d4\2\2>"+
		"k\5\b\5\r?@\f\13\2\2@A\7\u00d5\2\2Ak\5\b\5\fBC\f\n\2\2CD\t\5\2\2Dk\5\b"+
		"\5\13EF\f\t\2\2FG\t\4\2\2Gk\5\b\5\nHI\f\b\2\2IJ\t\6\2\2Jk\5\b\5\tKL\f"+
		"\7\2\2LM\t\7\2\2Mk\5\b\5\bNO\f\6\2\2OP\t\b\2\2Pk\5\b\5\7QR\f\4\2\2RS\t"+
		"\t\2\2Sk\5\b\5\5TU\f\3\2\2UV\7\u00e2\2\2Vk\5\b\5\3WX\f\22\2\2XZ\7\4\2"+
		"\2Y[\5\n\6\2ZY\3\2\2\2Z[\3\2\2\2[\\\3\2\2\2\\k\7\5\2\2]^\f\21\2\2^_\7"+
		"\6\2\2_`\5\b\5\2`a\7\7\2\2ak\3\2\2\2bc\f\20\2\2cd\7\b\2\2de\5\b\5\2ef"+
		"\7\t\2\2fk\3\2\2\2gh\f\5\2\2hi\t\n\2\2ik\5\20\t\2j9\3\2\2\2j<\3\2\2\2"+
		"j?\3\2\2\2jB\3\2\2\2jE\3\2\2\2jH\3\2\2\2jK\3\2\2\2jN\3\2\2\2jQ\3\2\2\2"+
		"jT\3\2\2\2jW\3\2\2\2j]\3\2\2\2jb\3\2\2\2jg\3\2\2\2kn\3\2\2\2lj\3\2\2\2"+
		"lm\3\2\2\2m\t\3\2\2\2nl\3\2\2\2or\b\6\1\2ps\5\b\5\2qs\5\f\7\2rp\3\2\2"+
		"\2rq\3\2\2\2s{\3\2\2\2tw\7\u00e3\2\2ux\5\b\5\2vx\5\f\7\2wu\3\2\2\2wv\3"+
		"\2\2\2xz\3\2\2\2yt\3\2\2\2z}\3\2\2\2{y\3\2\2\2{|\3\2\2\2|\u0087\3\2\2"+
		"\2}{\3\2\2\2~\u0080\f\3\2\2\177\u0081\7\u00e3\2\2\u0080\177\3\2\2\2\u0081"+
		"\u0082\3\2\2\2\u0082\u0080\3\2\2\2\u0082\u0083\3\2\2\2\u0083\u0084\3\2"+
		"\2\2\u0084\u0086\5\n\6\4\u0085~\3\2\2\2\u0086\u0089\3\2\2\2\u0087\u0085"+
		"\3\2\2\2\u0087\u0088\3\2\2\2\u0088\13\3\2\2\2\u0089\u0087\3\2\2\2\u008a"+
		"\u008b\7\22\2\2\u008b\u008c\7\u00df\2\2\u008c\u008d\7\f\2\2\u008d\u008e"+
		"\7\u00df\2\2\u008e\u0098\3\2\2\2\u008f\u0090\7\u00e3\2\2\u0090\u0092\7"+
		"\22\2\2\u0091\u008f\3\2\2\2\u0091\u0092\3\2\2\2\u0092\u0093\3\2\2\2\u0093"+
		"\u0094\7\u00df\2\2\u0094\u0095\7\f\2\2\u0095\u0097\7\u00df\2\2\u0096\u0091"+
		"\3\2\2\2\u0097\u009a\3\2\2\2\u0098\u0096\3\2\2\2\u0098\u0099\3\2\2\2\u0099"+
		"\u00a9\3\2\2\2\u009a\u0098\3\2\2\2\u009b\u009c\7\22\2\2\u009c\u00a0\7"+
		"\u00df\2\2\u009d\u009f\7\u00df\2\2\u009e\u009d\3\2\2\2\u009f\u00a2\3\2"+
		"\2\2\u00a0\u009e\3\2\2\2\u00a0\u00a1\3\2\2\2\u00a1\u00a9\3\2\2\2\u00a2"+
		"\u00a0\3\2\2\2\u00a3\u00a4\7\22\2\2\u00a4\u00a5\7\u00df\2\2\u00a5\u00a6"+
		"\7\b\2\2\u00a6\u00a7\7\r\2\2\u00a7\u00a9\7\t\2\2\u00a8\u008a\3\2\2\2\u00a8"+
		"\u009b\3\2\2\2\u00a8\u00a3\3\2\2\2\u00a9\r\3\2\2\2\u00aa\u00af\7\u00df"+
		"\2\2\u00ab\u00ac\7\u00df\2\2\u00ac\u00ad\7\f\2\2\u00ad\u00af\7\u00df\2"+
		"\2\u00ae\u00aa\3\2\2\2\u00ae\u00ab\3\2\2\2\u00af\u00b0\3\2\2\2\u00b0\u00ae"+
		"\3\2\2\2\u00b0\u00b1\3\2\2\2\u00b1\17\3\2\2\2\u00b2\u00c5\7\u00df\2\2"+
		"\u00b3\u00b6\7\4\2\2\u00b4\u00b7\5\24\13\2\u00b5\u00b7\5\22\n\2\u00b6"+
		"\u00b4\3\2\2\2\u00b6\u00b5\3\2\2\2\u00b7\u00bf\3\2\2\2\u00b8\u00bb\7\u00e3"+
		"\2\2\u00b9\u00bc\5\24\13\2\u00ba\u00bc\5\22\n\2\u00bb\u00b9\3\2\2\2\u00bb"+
		"\u00ba\3\2\2\2\u00bc\u00be\3\2\2\2\u00bd\u00b8\3\2\2\2\u00be\u00c1\3\2"+
		"\2\2\u00bf\u00bd\3\2\2\2\u00bf\u00c0\3\2\2\2\u00c0\u00c2\3\2\2\2\u00c1"+
		"\u00bf\3\2\2\2\u00c2\u00c3\7\5\2\2\u00c3\u00c5\3\2\2\2\u00c4\u00b2\3\2"+
		"\2\2\u00c4\u00b3\3\2\2\2\u00c5\21\3\2\2\2\u00c6\u00c7\7\u00dd\2\2\u00c7"+
		"\u00c8\7\23\2\2\u00c8\u00c9\7\u00dd\2\2\u00c9\23\3\2\2\2\u00ca\u00cb\t"+
		"\13\2\2\u00cb\25\3\2\2\2\u00cc\u00cd\b\f\1\2\u00cd\u00d2\7\u00df\2\2\u00ce"+
		"\u00d2\7\u00a6\2\2\u00cf\u00d2\7\u008e\2\2\u00d0\u00d2\7\u00ab\2\2\u00d1"+
		"\u00cc\3\2\2\2\u00d1\u00ce\3\2\2\2\u00d1\u00cf\3\2\2\2\u00d1\u00d0\3\2"+
		"\2\2\u00d2\u00d8\3\2\2\2\u00d3\u00d4\f\7\2\2\u00d4\u00d5\7\u00e0\2\2\u00d5"+
		"\u00d7\5\26\f\b\u00d6\u00d3\3\2\2\2\u00d7\u00da\3\2\2\2\u00d8\u00d6\3"+
		"\2\2\2\u00d8\u00d9\3\2\2\2\u00d9\27\3\2\2\2\u00da\u00d8\3\2\2\2\31\33"+
		"%\67Zjlrw{\u0082\u0087\u0091\u0098\u00a0\u00a8\u00ae\u00b0\u00b6\u00bb"+
		"\u00bf\u00c4\u00d1\u00d8";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}