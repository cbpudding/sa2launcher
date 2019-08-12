#include <stdio.h>
#include <stdlib.h>

void write_config(FILE *config, int width, int height) {
	char buffer[256];
	sprintf(buffer, "<Configs FullScreen=\"1\" Display=\"0\" Res=\"22\" Width=\"%u\" Height=\"%u\" RefreshRate=\"60\" Language=\"0\" Analytics=\"0\" />", width, height);
	fputs(buffer, config);
}

void write_keys(FILE *config, int keys[], int count) {
	char buffer[22];
	for(int i = 0; i < count; i++) {
		sprintf(buffer, "<key index=\"%u\" />\r\n", keys[i]);
		fputs(buffer, config);
	}
}

int main(int argc, char *argv[]) {
	FILE *keyboard;
	FILE *user_config;
	if((user_config = fopen("Config/UserConfig.cfg", "w"))) {
		if((keyboard = fopen("Config/Keyboard.cfg", "w"))) {
			// UserConfig.cfg
			fputs("<?xml version=\"1.0\" ?>\r\n", user_config);
			write_config(user_config, 640, 480);
			// Keyboard.cfg
			fputs("<?xml version=\"1.0\" ?>\r\n", keyboard);
			fputs("<Setup Layout=\"0\" />\r\n", keyboard);
			fputs("<Players>\r\n", keyboard);
			fputs("<Player InputWay=\"1\" Vibrate=\"0\">\r\n", keyboard);
			int input_zero[] = {83, 65, 73, 79, 5, 52, 56, 54, 25, 16, 37, 23, 4, 37, 27, 67};
			write_keys(keyboard, input_zero, 16);
			fputs("</Player>\r\n", keyboard);
			fputs("<Player InputWay=\"0\" Vibrate=\"0\">\r\n", keyboard);
			int input_one[] = {22, 18, 0, 3, 102, 98, 101, 99, 66, 104, 37, 76, 105, 37, 28, 111};
			write_keys(keyboard, input_one, 16);
			fputs("</Player>\r\n", keyboard);
			fputs("</Players>", keyboard);
			system("start sonic2app.exe");
			fclose(keyboard);
		}
		fclose(user_config);
	}
	return 0;
}
