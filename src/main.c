#include <raylib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define CELL_SIZE 5

static uint8_t ruleset = 165;
uint8_t generate_state(uint8_t current, uint8_t left, uint8_t right);

int main(void) {
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Celluar automata");
	SetTargetFPS(30);

	uint32_t max_columns = WINDOW_WIDTH / CELL_SIZE, max_rows = WINDOW_HEIGHT / CELL_SIZE;
	uint32_t cells[max_columns * max_rows];
	uint32_t* source_array = cells;
	uint32_t* update_array = cells + max_columns;

	for (int row = 0; row < max_rows; row++) {
		for (int column = 0; column < max_columns; column++) {
			uint32_t index = column + (row * max_columns);
			cells[index] = 0;
		}
	}
	cells[max_columns / 2] = 1;

	uint32_t row = 0;

	ClearBackground(RAYWHITE);
	while (!WindowShouldClose()) {
		if (row > max_rows) {
			BeginDrawing();
			EndDrawing();

			continue;
		}
		BeginDrawing();

		for (int column = 0; column < max_columns; column++) {
			Color color = {
				.r = 0,
				.g = 0,
				.b = 0,
				.a = source_array[column] * 255
			};
			DrawRectangle(column * CELL_SIZE, row * CELL_SIZE, CELL_SIZE, CELL_SIZE, color);
		}
		row++;

		for (int column = 0; column < max_columns; column++) {
			uint8_t left = column > 0 ? source_array[column - 1] : source_array[max_columns - 1];
			uint8_t right = column < (max_columns - 1) ? source_array[column + 1] : source_array[0];
			uint8_t current = source_array[column];

			uint8_t new_state = generate_state(current, left, right);
			update_array[column] = new_state;
		}

		uint32_t* tmp = source_array;
		source_array = update_array;
		update_array = tmp;

		EndDrawing();
	}

	CloseWindow();
	return 0;
}

uint8_t generate_state(uint8_t current, uint8_t left, uint8_t right) {
	uint8_t index = ((left << 0) | (current << 1) | (right << 2));
	return (ruleset >> index) & 1;
}
