// Generated from StatComp.g4 by ANTLR 4.13.2
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue", "this-escape"})
public class StatCompParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, POW=2, ADD=3, SUB=4, MUL=5, DIV=6, INTDIV=7, MOD=8, ASSIGN=9, 
		LPAR=10, RPAR=11, COLON=12, LBRACE=13, RBRACE=14, LBRACK=15, RBRACK=16, 
		COMMA=17, TINT=18, TFLOAT=19, ARRAY=20, ID=21, INT=22, FLOAT=23, WS=24;
	public static final int
		RULE_prog = 0, RULE_stmt = 1, RULE_expr = 2, RULE_arrayInit = 3, RULE_num = 4, 
		RULE_decltype = 5;
	private static String[] makeRuleNames() {
		return new String[] {
			"prog", "stmt", "expr", "arrayInit", "num", "decltype"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "';'", "'^'", "'+'", "'-'", "'*'", "'/'", "'//'", "'%'", "'='", 
			"'('", "')'", "':'", "'{'", "'}'", "'['", "']'", "','", "'int'", "'float'", 
			"'array'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, "POW", "ADD", "SUB", "MUL", "DIV", "INTDIV", "MOD", "ASSIGN", 
			"LPAR", "RPAR", "COLON", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "COMMA", 
			"TINT", "TFLOAT", "ARRAY", "ID", "INT", "FLOAT", "WS"
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
	public String getGrammarFileName() { return "StatComp.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public StatCompParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ProgContext extends ParserRuleContext {
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
		}
		public ProgContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_prog; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).enterProg(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).exitProg(this);
		}
	}

	public final ProgContext prog() throws RecognitionException {
		ProgContext _localctx = new ProgContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_prog);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(15);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 16516112L) != 0)) {
				{
				{
				setState(12);
				stmt();
				}
				}
				setState(17);
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

	@SuppressWarnings("CheckReturnValue")
	public static class StmtContext extends ParserRuleContext {
		public StmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stmt; }
	 
		public StmtContext() { }
		public void copyFrom(StmtContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class UpdateSymbolContext extends StmtContext {
		public DecltypeContext decltype() {
			return getRuleContext(DecltypeContext.class,0);
		}
		public TerminalNode ID() { return getToken(StatCompParser.ID, 0); }
		public TerminalNode ASSIGN() { return getToken(StatCompParser.ASSIGN, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public UpdateSymbolContext(StmtContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).enterUpdateSymbol(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).exitUpdateSymbol(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ArrayDeclContext extends StmtContext {
		public TerminalNode ARRAY() { return getToken(StatCompParser.ARRAY, 0); }
		public DecltypeContext decltype() {
			return getRuleContext(DecltypeContext.class,0);
		}
		public TerminalNode ID() { return getToken(StatCompParser.ID, 0); }
		public TerminalNode ASSIGN() { return getToken(StatCompParser.ASSIGN, 0); }
		public ArrayInitContext arrayInit() {
			return getRuleContext(ArrayInitContext.class,0);
		}
		public ArrayDeclContext(StmtContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).enterArrayDecl(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).exitArrayDecl(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class PrintExprContext extends StmtContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public PrintExprContext(StmtContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).enterPrintExpr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).exitPrintExpr(this);
		}
	}

	public final StmtContext stmt() throws RecognitionException {
		StmtContext _localctx = new StmtContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_stmt);
		try {
			setState(34);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case SUB:
			case LPAR:
			case ID:
			case INT:
			case FLOAT:
				_localctx = new PrintExprContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(18);
				expr(0);
				setState(19);
				match(T__0);
				}
				break;
			case TINT:
			case TFLOAT:
				_localctx = new UpdateSymbolContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(21);
				decltype();
				setState(22);
				match(ID);
				setState(23);
				match(ASSIGN);
				setState(24);
				expr(0);
				setState(25);
				match(T__0);
				}
				break;
			case ARRAY:
				_localctx = new ArrayDeclContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(27);
				match(ARRAY);
				setState(28);
				decltype();
				setState(29);
				match(ID);
				setState(30);
				match(ASSIGN);
				setState(31);
				arrayInit();
				setState(32);
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

	@SuppressWarnings("CheckReturnValue")
	public static class ExprContext extends ParserRuleContext {
		public ExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr; }
	 
		public ExprContext() { }
		public void copyFrom(ExprContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprNegContext extends ExprContext {
		public TerminalNode SUB() { return getToken(StatCompParser.SUB, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ExprNegContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).enterExprNeg(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).exitExprNeg(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprParContext extends ExprContext {
		public TerminalNode LPAR() { return getToken(StatCompParser.LPAR, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode RPAR() { return getToken(StatCompParser.RPAR, 0); }
		public ExprParContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).enterExprPar(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).exitExprPar(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprAddSubContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode ADD() { return getToken(StatCompParser.ADD, 0); }
		public TerminalNode SUB() { return getToken(StatCompParser.SUB, 0); }
		public ExprAddSubContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).enterExprAddSub(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).exitExprAddSub(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprVarContext extends ExprContext {
		public TerminalNode ID() { return getToken(StatCompParser.ID, 0); }
		public ExprVarContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).enterExprVar(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).exitExprVar(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprPowContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode POW() { return getToken(StatCompParser.POW, 0); }
		public ExprPowContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).enterExprPow(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).exitExprPow(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprLiteralContext extends ExprContext {
		public NumContext num() {
			return getRuleContext(NumContext.class,0);
		}
		public ExprLiteralContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).enterExprLiteral(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).exitExprLiteral(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprArrayAccessContext extends ExprContext {
		public TerminalNode ID() { return getToken(StatCompParser.ID, 0); }
		public TerminalNode LBRACK() { return getToken(StatCompParser.LBRACK, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode RBRACK() { return getToken(StatCompParser.RBRACK, 0); }
		public ExprArrayAccessContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).enterExprArrayAccess(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).exitExprArrayAccess(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprMulDivContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode MUL() { return getToken(StatCompParser.MUL, 0); }
		public TerminalNode DIV() { return getToken(StatCompParser.DIV, 0); }
		public TerminalNode INTDIV() { return getToken(StatCompParser.INTDIV, 0); }
		public TerminalNode MOD() { return getToken(StatCompParser.MOD, 0); }
		public ExprMulDivContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).enterExprMulDiv(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).exitExprMulDiv(this);
		}
	}

	public final ExprContext expr() throws RecognitionException {
		return expr(0);
	}

	private ExprContext expr(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExprContext _localctx = new ExprContext(_ctx, _parentState);
		ExprContext _prevctx = _localctx;
		int _startState = 4;
		enterRecursionRule(_localctx, 4, RULE_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(50);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				{
				_localctx = new ExprNegContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(37);
				match(SUB);
				setState(38);
				expr(8);
				}
				break;
			case 2:
				{
				_localctx = new ExprParContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(39);
				match(LPAR);
				setState(40);
				expr(0);
				setState(41);
				match(RPAR);
				}
				break;
			case 3:
				{
				_localctx = new ExprLiteralContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(43);
				num();
				}
				break;
			case 4:
				{
				_localctx = new ExprVarContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(44);
				match(ID);
				}
				break;
			case 5:
				{
				_localctx = new ExprArrayAccessContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(45);
				match(ID);
				setState(46);
				match(LBRACK);
				setState(47);
				expr(0);
				setState(48);
				match(RBRACK);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(63);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(61);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
					case 1:
						{
						_localctx = new ExprPowContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(52);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(53);
						match(POW);
						setState(54);
						expr(8);
						}
						break;
					case 2:
						{
						_localctx = new ExprMulDivContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(55);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(56);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 480L) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(57);
						expr(7);
						}
						break;
					case 3:
						{
						_localctx = new ExprAddSubContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(58);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(59);
						_la = _input.LA(1);
						if ( !(_la==ADD || _la==SUB) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(60);
						expr(6);
						}
						break;
					}
					} 
				}
				setState(65);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
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
	public static class ArrayInitContext extends ParserRuleContext {
		public TerminalNode LBRACE() { return getToken(StatCompParser.LBRACE, 0); }
		public TerminalNode RBRACE() { return getToken(StatCompParser.RBRACE, 0); }
		public List<NumContext> num() {
			return getRuleContexts(NumContext.class);
		}
		public NumContext num(int i) {
			return getRuleContext(NumContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(StatCompParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(StatCompParser.COMMA, i);
		}
		public ArrayInitContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arrayInit; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).enterArrayInit(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).exitArrayInit(this);
		}
	}

	public final ArrayInitContext arrayInit() throws RecognitionException {
		ArrayInitContext _localctx = new ArrayInitContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_arrayInit);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(66);
			match(LBRACE);
			setState(75);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==INT || _la==FLOAT) {
				{
				setState(67);
				num();
				setState(72);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMMA) {
					{
					{
					setState(68);
					match(COMMA);
					setState(69);
					num();
					}
					}
					setState(74);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
			}

			setState(77);
			match(RBRACE);
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
	public static class NumContext extends ParserRuleContext {
		public TerminalNode INT() { return getToken(StatCompParser.INT, 0); }
		public TerminalNode FLOAT() { return getToken(StatCompParser.FLOAT, 0); }
		public NumContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_num; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).enterNum(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).exitNum(this);
		}
	}

	public final NumContext num() throws RecognitionException {
		NumContext _localctx = new NumContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_num);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(79);
			_la = _input.LA(1);
			if ( !(_la==INT || _la==FLOAT) ) {
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
	public static class DecltypeContext extends ParserRuleContext {
		public TerminalNode TINT() { return getToken(StatCompParser.TINT, 0); }
		public TerminalNode TFLOAT() { return getToken(StatCompParser.TFLOAT, 0); }
		public DecltypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_decltype; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).enterDecltype(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof StatCompListener ) ((StatCompListener)listener).exitDecltype(this);
		}
	}

	public final DecltypeContext decltype() throws RecognitionException {
		DecltypeContext _localctx = new DecltypeContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_decltype);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(81);
			_la = _input.LA(1);
			if ( !(_la==TINT || _la==TFLOAT) ) {
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

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 2:
			return expr_sempred((ExprContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expr_sempred(ExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 7);
		case 1:
			return precpred(_ctx, 6);
		case 2:
			return precpred(_ctx, 5);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001\u0018T\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0001\u0000\u0005\u0000\u000e\b\u0000\n\u0000\f\u0000"+
		"\u0011\t\u0000\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0003\u0001"+
		"#\b\u0001\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0003\u00023\b\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0005\u0002>\b\u0002\n\u0002\f\u0002A\t\u0002"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0005\u0003G\b\u0003"+
		"\n\u0003\f\u0003J\t\u0003\u0003\u0003L\b\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0004\u0001\u0004\u0001\u0005\u0001\u0005\u0001\u0005\u0000\u0001"+
		"\u0004\u0006\u0000\u0002\u0004\u0006\b\n\u0000\u0004\u0001\u0000\u0005"+
		"\b\u0001\u0000\u0003\u0004\u0001\u0000\u0016\u0017\u0001\u0000\u0012\u0013"+
		"Y\u0000\u000f\u0001\u0000\u0000\u0000\u0002\"\u0001\u0000\u0000\u0000"+
		"\u00042\u0001\u0000\u0000\u0000\u0006B\u0001\u0000\u0000\u0000\bO\u0001"+
		"\u0000\u0000\u0000\nQ\u0001\u0000\u0000\u0000\f\u000e\u0003\u0002\u0001"+
		"\u0000\r\f\u0001\u0000\u0000\u0000\u000e\u0011\u0001\u0000\u0000\u0000"+
		"\u000f\r\u0001\u0000\u0000\u0000\u000f\u0010\u0001\u0000\u0000\u0000\u0010"+
		"\u0001\u0001\u0000\u0000\u0000\u0011\u000f\u0001\u0000\u0000\u0000\u0012"+
		"\u0013\u0003\u0004\u0002\u0000\u0013\u0014\u0005\u0001\u0000\u0000\u0014"+
		"#\u0001\u0000\u0000\u0000\u0015\u0016\u0003\n\u0005\u0000\u0016\u0017"+
		"\u0005\u0015\u0000\u0000\u0017\u0018\u0005\t\u0000\u0000\u0018\u0019\u0003"+
		"\u0004\u0002\u0000\u0019\u001a\u0005\u0001\u0000\u0000\u001a#\u0001\u0000"+
		"\u0000\u0000\u001b\u001c\u0005\u0014\u0000\u0000\u001c\u001d\u0003\n\u0005"+
		"\u0000\u001d\u001e\u0005\u0015\u0000\u0000\u001e\u001f\u0005\t\u0000\u0000"+
		"\u001f \u0003\u0006\u0003\u0000 !\u0005\u0001\u0000\u0000!#\u0001\u0000"+
		"\u0000\u0000\"\u0012\u0001\u0000\u0000\u0000\"\u0015\u0001\u0000\u0000"+
		"\u0000\"\u001b\u0001\u0000\u0000\u0000#\u0003\u0001\u0000\u0000\u0000"+
		"$%\u0006\u0002\uffff\uffff\u0000%&\u0005\u0004\u0000\u0000&3\u0003\u0004"+
		"\u0002\b\'(\u0005\n\u0000\u0000()\u0003\u0004\u0002\u0000)*\u0005\u000b"+
		"\u0000\u0000*3\u0001\u0000\u0000\u0000+3\u0003\b\u0004\u0000,3\u0005\u0015"+
		"\u0000\u0000-.\u0005\u0015\u0000\u0000./\u0005\u000f\u0000\u0000/0\u0003"+
		"\u0004\u0002\u000001\u0005\u0010\u0000\u000013\u0001\u0000\u0000\u0000"+
		"2$\u0001\u0000\u0000\u00002\'\u0001\u0000\u0000\u00002+\u0001\u0000\u0000"+
		"\u00002,\u0001\u0000\u0000\u00002-\u0001\u0000\u0000\u00003?\u0001\u0000"+
		"\u0000\u000045\n\u0007\u0000\u000056\u0005\u0002\u0000\u00006>\u0003\u0004"+
		"\u0002\b78\n\u0006\u0000\u000089\u0007\u0000\u0000\u00009>\u0003\u0004"+
		"\u0002\u0007:;\n\u0005\u0000\u0000;<\u0007\u0001\u0000\u0000<>\u0003\u0004"+
		"\u0002\u0006=4\u0001\u0000\u0000\u0000=7\u0001\u0000\u0000\u0000=:\u0001"+
		"\u0000\u0000\u0000>A\u0001\u0000\u0000\u0000?=\u0001\u0000\u0000\u0000"+
		"?@\u0001\u0000\u0000\u0000@\u0005\u0001\u0000\u0000\u0000A?\u0001\u0000"+
		"\u0000\u0000BK\u0005\r\u0000\u0000CH\u0003\b\u0004\u0000DE\u0005\u0011"+
		"\u0000\u0000EG\u0003\b\u0004\u0000FD\u0001\u0000\u0000\u0000GJ\u0001\u0000"+
		"\u0000\u0000HF\u0001\u0000\u0000\u0000HI\u0001\u0000\u0000\u0000IL\u0001"+
		"\u0000\u0000\u0000JH\u0001\u0000\u0000\u0000KC\u0001\u0000\u0000\u0000"+
		"KL\u0001\u0000\u0000\u0000LM\u0001\u0000\u0000\u0000MN\u0005\u000e\u0000"+
		"\u0000N\u0007\u0001\u0000\u0000\u0000OP\u0007\u0002\u0000\u0000P\t\u0001"+
		"\u0000\u0000\u0000QR\u0007\u0003\u0000\u0000R\u000b\u0001\u0000\u0000"+
		"\u0000\u0007\u000f\"2=?HK";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}