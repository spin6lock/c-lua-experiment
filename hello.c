#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#include <stdlib.h>
#include <stdio.h>

void bail(lua_State *L, char *msg) {
	fprintf(stderr, "\nFatal Error:\n %s: %s\n\n",
			msg, lua_tostring(L, -1));
	exit(1);
}

int main(void) {
	lua_State *L;
	L = luaL_newstate();
	luaL_openlibs(L);

	if (luaL_loadfile(L, "helloscript.lua")) {
		bail(L, "luaL_loadfile() failed");
	}

	printf("In C, calling Lua\n");

	if (lua_pcall(L, 0, 0, 0)) {
		bail(L, "lua_pcall() failed");
	}

	printf("Back in C again \n");

	lua_close(L);

	return 0;
}
