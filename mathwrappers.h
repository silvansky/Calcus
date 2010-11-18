/************************************************************************
 * Provides wrappers for standard <math.h> functions for QtScript usage *
 ************************************************************************/

#ifndef MATHWRAPPERS_H
#define MATHWRAPPERS_H

#include <math.h>
#include <QtScript>
/*
	Wrappers for these functions:

	double sin (double);
	double cos (double);
	double tan (double);
	double sinh (double);
	double cosh (double);
	double tanh (double);
	double asin (double);
	double acos (double);
	double atan (double);
	double atan2 (double, double);
	double exp (double);
	double log (double);
	double log10 (double);
	double pow (double, double);
	double sqrt (double);
	double ceil (double);
	double floor (double);
	double fabs (double);
*/
namespace CalcusMath {

QScriptValue sin(QScriptContext *context, QScriptEngine *engine)
{
	double x = context->argument(0).toNumber();
	return ::sin(x);
}

QScriptValue cos(QScriptContext *context, QScriptEngine *engine)
{
	double x = context->argument(0).toNumber();
	return ::cos(x);
}

QScriptValue tan(QScriptContext *context, QScriptEngine *engine)
{
	double x = context->argument(0).toNumber();
	return ::tan(x);
}

QScriptValue sinh(QScriptContext *context, QScriptEngine *engine)
{
	double x = context->argument(0).toNumber();
	return ::sinh(x);
}

QScriptValue cosh(QScriptContext *context, QScriptEngine *engine)
{
	double x = context->argument(0).toNumber();
	return ::cosh(x);
}

QScriptValue tanh(QScriptContext *context, QScriptEngine *engine)
{
	double x = context->argument(0).toNumber();
	return ::tanh(x);
}

QScriptValue asin(QScriptContext *context, QScriptEngine *engine)
{
	double x = context->argument(0).toNumber();
	return ::asin(x);
}

QScriptValue acos(QScriptContext *context, QScriptEngine *engine)
{
	double x = context->argument(0).toNumber();
	return ::acos(x);
}

QScriptValue atan(QScriptContext *context, QScriptEngine *engine)
{
	double x = context->argument(0).toNumber();
	return ::atan(x);
}

QScriptValue atan2(QScriptContext *context, QScriptEngine *engine)
{
	double x = context->argument(0).toNumber();
	double y = context->argument(1).toNumber();
	return ::atan2(x, y);
}

QScriptValue exp(QScriptContext *context, QScriptEngine *engine)
{
	double x = context->argument(0).toNumber();
	return ::exp(x);
}

QScriptValue log(QScriptContext *context, QScriptEngine *engine)
{
	double x = context->argument(0).toNumber();
	return ::log(x);
}

QScriptValue log10(QScriptContext *context, QScriptEngine *engine)
{
	double x = context->argument(0).toNumber();
	return ::log10(x);
}

QScriptValue pow(QScriptContext *context, QScriptEngine *engine)
{
	double x = context->argument(0).toNumber();
	double y = context->argument(1).toNumber();
	return ::pow(x, y);
}

QScriptValue sqrt(QScriptContext *context, QScriptEngine *engine)
{
	double x = context->argument(0).toNumber();
	return ::sqrt(x);
}

QScriptValue ceil(QScriptContext *context, QScriptEngine *engine)
{
	double x = context->argument(0).toNumber();
	return ::ceil(x);
}

QScriptValue floor(QScriptContext *context, QScriptEngine *engine)
{
	double x = context->argument(0).toNumber();
	return ::floor(x);
}

QScriptValue fabs(QScriptContext *context, QScriptEngine *engine)
{
	double x = context->argument(0).toNumber();
	return ::fabs(x);
}

void registerWrappers(QScriptEngine * engine)
{
	engine->globalObject().setProperty("sin", engine->newFunction(sin, 1));
	engine->globalObject().setProperty("cos", engine->newFunction(cos, 1));
	engine->globalObject().setProperty("tan", engine->newFunction(tan, 1));
	engine->globalObject().setProperty("sinh", engine->newFunction(sinh, 1));
	engine->globalObject().setProperty("cosh", engine->newFunction(cosh, 1));
	engine->globalObject().setProperty("tanh", engine->newFunction(tanh, 1));
	engine->globalObject().setProperty("asin", engine->newFunction(asin, 1));
	engine->globalObject().setProperty("acos", engine->newFunction(acos, 1));
	engine->globalObject().setProperty("atan", engine->newFunction(atan, 1));
	engine->globalObject().setProperty("atan2", engine->newFunction(atan2, 2));
	engine->globalObject().setProperty("exp", engine->newFunction(exp, 1));
	engine->globalObject().setProperty("log", engine->newFunction(log, 1));
	engine->globalObject().setProperty("log10", engine->newFunction(log10, 1));
	engine->globalObject().setProperty("pow", engine->newFunction(pow, 2));
	engine->globalObject().setProperty("sqrt", engine->newFunction(sqrt, 1));
	engine->globalObject().setProperty("ceil", engine->newFunction(ceil, 1));
	engine->globalObject().setProperty("floor", engine->newFunction(floor, 1));
	engine->globalObject().setProperty("fabs", engine->newFunction(fabs, 1));
	// registering the "pi" number
	engine->globalObject().setProperty("pi", 2.0 * ::acos(0));
}

} // end of namespace Calcus

#endif // MATHWRAPPERS_H
