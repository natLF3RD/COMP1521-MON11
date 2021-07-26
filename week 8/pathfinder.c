#include <sys/types.h>

#include <sys/fcntl.h>
#include <sys/stat.h>

#include <assert.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static bool path_check (char **, char *);
static bool path_check_one (char *, char *);

static char **tokenize (char *, char *);
static void free_tokens (char **);

int
main (int argc, char *argv[])
{
	char *path_env = getenv ("PATH");
	char **path_dirs = tokenize (path_env, ":");

	assert (argc >= 1);
	for (int i = 1; i < argc; i++)
		path_check (path_dirs, argv[i]);

	free_tokens (path_dirs);

	return 0;
}

//
// check if `name' is in any of `path'.
//
static bool
path_check (char **path, char *name)
{
	assert (path != NULL);
	assert (name != NULL);

	bool match = false;
	for (char **dir = path; *dir != NULL; dir++) {
		if (! path_check_one (*dir, name)) continue;
		match = true;
	}

	if (! match)
		printf ("%s not found\n", name);

	return match;
}

//
// check if `name' is in `path'
//
static bool
path_check_one (char *dir, char *name)
{
	assert (dir != NULL);
	assert (name != NULL);

	size_t pathlen = strlen (dir) + 1 + strlen (name) + 1;
	char *pathname = malloc (pathlen);
	assert (pathname != NULL);
	snprintf (pathname, pathlen, "%s/%s", dir, name);

	bool ok = faccessat (AT_FDCWD, pathname, X_OK, AT_EACCESS) == 0;
	if (ok) puts (pathname);

	free (pathname);
	return ok;
}

//
// Split a string 'str' into pieces by any one of a set of separators.
// Returns an array of strings, with the last element being `NULL'.
// The array itself, and the strings, are allocated with `malloc(3)';
// the provided `free_token' function can deallocate this.
//
static char **
tokenize (char *str, char *sep)
{
	size_t n_tokens = 0;
	char **tokens = NULL;

	while (*str != '\0') {
		// We are pointing at zero or more of any of the separators.
		// Skip all leading instances of the separators.
		str += strspn (str, sep);

		// Trailing separators after the last token mean that, at this
		// point, we are looking at the end of the string, so:
		if (*str == '\0')
			break;

		// Now, `s' points at one or more characters we want to keep.
		// The number of non-separator characters is the token length.
		// Allocate a copy of the token, and preserve it.
		size_t len = strcspn (str, sep);
		char *tok = strndup (str, len);
		assert (tok != NULL);
		str += len;

		// Add this token.  (Should really use reallocarray(3) here.)
		tokens = realloc (tokens, ++n_tokens * sizeof *tokens);
		tokens[n_tokens - 1] = tok;
	}

	// Add the final `NULL'.
	tokens = realloc (tokens, ++n_tokens * sizeof *tokens);
	tokens[n_tokens - 1] = NULL;

	return tokens;
}

//
// Free an array of strings.
//
static void
free_tokens (char **tokens)
{
	for (int i = 0; tokens != NULL && tokens[i] != NULL; i++)
		free (tokens[i]);

	free (tokens);
}