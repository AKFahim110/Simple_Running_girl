Practice - 1

#include <stdio.h>
#include <graphics.h>
#include "conio.h"
#include "EasyXPng.h"

#define WIDTH  800
#define HEIGHT 600
#define ROAD_Y 380    // Adjust this value to match your road's y-position
#define FRAMES 4

int speed = -10; // Move to the left
int x = WIDTH;   // Start position off the right edge

int main() {
	IMAGE im_bk;
	initgraph(WIDTH, HEIGHT);

	int i = 0;
	TCHAR filename[100];
	IMAGE img[FRAMES];

	// Load animation frames
	for (i = 0; i < FRAMES; i++) {
		_stprintf_s(filename, 100, _T("Z:\\Desktop\\assets\\g\\g%d.png"), i);
		loadimage(&img[i], filename);
	}

	loadimage(&im_bk, _T("Z:\\Desktop\\assets\\Materials\\bg1.png"));

	i = 0;
	BeginBatchDraw();
	while (1) {
		putimage(0, 0, &im_bk); // Draw the background

		// Draw the character image
		putimagePng(x, ROAD_Y, &img[i]);

		// Update position
		x += speed;

		// Update frame index for animation
		i = (i + 1) % FRAMES;

		// Reset position if it goes off the screen
		if (x < -50) { // Adjust to account for the image width
			x = WIDTH; // Reset position to the right edge
		}

		Sleep(60); // Control frame rate
		FlushBatchDraw(); // Refresh the screen

		// Exit condition (press ESC to quit)
		if (GetAsyncKeyState(VK_ESCAPE)) {
			break;
		}
	}

	closegraph();
	return 0;
}