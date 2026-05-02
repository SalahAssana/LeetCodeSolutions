class Solution {
public:
    double separateSquares(vector<vector<int>>& squares)
    {
        double balance = 0;
        double right = 0, left = 1e10;
        double y = 0;
        double result = 1e10;
        double upper, lower;

        sort(squares.begin(), squares.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] + a[2]) < (b[1] + b[2]);
        });

        for (auto& square : squares) {
            left = min(left, (double)square[1]);
            right = max(right, (double)(square[1] + square[2]));
        }

        while ((left < right) && (fabs(right - left) > 1e-6)) {
            y = (left + right) / 2;
            balance = 0;
            for (auto& sq : squares) {
                upper = calculateUpperArea(y, sq);
                lower = (double)sq[2] * sq[2] - upper;
                balance += upper - lower;
            }

            if (balance > 0)
                left = y;
            else if (balance < 0)
                right = y;
            else if (fabs(balance) < 1e-5) {
                result = y;
                break;
            }
        }
        result = y;

        for (auto& sq : squares) {
            const double up = sq[1] + sq[2];
            if (y > sq[1] && y < up) {
                result = y;
                break;
            }

            if (up < y) {
                result = up;
            }
        }

        return result;
    }

    double calculateUpperArea(double cy, const vector<int>& square)
    {
        const double x = square[0], y = square[1], l = square[2];
        const double hy = cy - y;
        double height = l;

        height -= (hy > l) * l;
        height -= (hy >= 0 && hy <= l) * hy;

        return height * l;
    }
};
