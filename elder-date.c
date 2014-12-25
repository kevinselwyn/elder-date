#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static char *months[12] = {
	"Morning Star",
	"Sun's Dawn",
	"First Seed",
	"Rain's Hand",
	"Second Seed",
	"Midyear",
	"Sun's Height",
	"Last Seed",
	"Hearthfire",
	"Frostfall",
	"Sun's Dusk",
	"Evening Star"
};

static char *days[7] = {
	"Sun", "Morn", "Tir", "Mid", "Tur", "Fre", "Lore"
};

int main() {
	int rc = 0, day = 0;
	char *suffix = NULL;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	day = tm.tm_mday;
	suffix = malloc(sizeof(char) * 2 + 1);

	if (!suffix) {
		printf("Memory error\n");

		rc = 1;
		goto cleanup;
	}

	strcpy(suffix, "th");

	if (day < 11 || 13 < day) {
		switch (day) {
		case 1:
			strcpy(suffix, "st");
			break;
		case 2:
			strcpy(suffix, "nd");
			break;
		case 3:
			strcpy(suffix, "rd");
			break;
		}
	}

	printf("%sdas, %d%s day of %s\n", days[tm.tm_wday], tm.tm_mday, suffix, months[tm.tm_mon]);

cleanup:
	if (suffix) {
		free(suffix);
	}

	return rc;
}