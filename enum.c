# include <stdio.h>

enum WeekDay {
	MonDay=4, ThuesDay, WednesDay, ThursDay, FriDay, SaturDay,
	SunDay
};

int main(void) {
	enum WeekDay day = WednesDay;
	printf("%d\n", day);
	return 0;
}
