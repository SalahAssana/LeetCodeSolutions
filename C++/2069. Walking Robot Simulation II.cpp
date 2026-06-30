class Robot {
public:
    Robot(int width, int height)
    {
        this->width = width;
        this->height = height;

        perimeter = 2 * (width + height) - 4;
    }

    void step(int num)
    {
        moved = 1;
        num %= perimeter;
        pos = (pos + num) % perimeter;

        if (pos >= 1 && pos < width) {
            current_direction = "East";
        } // East
        else if (pos >= width && pos < (width - 1) + height) {
            current_direction = "North";
        } else if (pos >= (width - 1) + height && pos < (width + width + height - 2)) {
            current_direction = "West";
        } else {
            current_direction = "South";
        }
    }

    vector<int> getPos()
    {
        if (current_direction == "East") {
            return { pos, 0 };
        } else if (current_direction == "North") {
            return { width - 1, pos - width + 1 };
        } else if (current_direction == "West") {
            return { width - pos + width + height - 3, height - 1 };
        } else {
            return { 0, pos == 0 ? 0 : (width + width + height + height - 4 - pos) };
        }

        return { -1, -1 };
    }

    string getDir()
    {
        return current_direction;
    }

private:
    string current_direction = "East";

    int pos = 0;
    int width, height;
    int perimeter;
    int moved = 0;
};
