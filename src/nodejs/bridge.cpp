#include <node.h>
#include <v8.h>

#include "SDL.h"
#include "SDL_thread.h"

#include "cube.h"

using namespace v8;

extern int sauermain(int argc, char **argv);

struct main_thread_args {int argc; char **argv; };
typedef struct main_thread_args mtargs;


int main_thread(void* a__) {
  mtargs *a = (mtargs*)a__;
  return sauermain(a->argc, a->argv);
}

Handle<Value> CallMain(const Arguments& js_args) {
  HandleScope scope;

  mtargs *c_args = (mtargs*)malloc(sizeof(mtargs));

  c_args->argc = js_args.Length();
  c_args->argv = (char**)malloc(sizeof(char*) * c_args->argc);

  for (size_t an = 0; an < c_args->argc; an++) {
    Local<String> js_s = js_args[an]->ToString();
    size_t len = js_s->Utf8Length();

    char* c_s = (char*)malloc(len);
    js_s->WriteUtf8(c_s, len);
    
    c_args->argv[an] = c_s; 
  }

  SDL_CreateThread(main_thread, c_args);

  return scope.Close(String::New("fnord"));
}

Handle<Value> EvalCubescript(const Arguments& js_args) {
  HandleScope scope;

  Local<String> js_s = js_args[0]->ToString();
  size_t len = js_s->Utf8Length();

  char* c_s = (char*)alloca(len);
  js_s->WriteUtf8(c_s, len);

  execute(c_s);

  return scope.Close(String::New("fnord"));
}

void init(Handle<Object> exports) {
  exports->Set(String::NewSymbol("main"),
      FunctionTemplate::New(CallMain)->GetFunction());
  exports->Set(String::NewSymbol("eval"),
      FunctionTemplate::New(EvalCubescript)->GetFunction());
}

NODE_MODULE(sauer, init)
