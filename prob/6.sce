m_values = [0.5, 1.5, -1.5];
s_values = [1, 1.5, 2];

clf();

for m = m_values
    for s = s_values
        x = linspace(m - 4 * s, m + 4 * s, 100);
        y = (1 / (s * sqrt(2 * %pi))) * exp(-(x - m).^2 / (2 * s^2));
        plot(x, y);
        hold on;
    end
end

xgrid();
legend(["m=0.5, s=1", "m=1.5, s=1.5", "m=-1.5, s=2"]);
xlabel("x");
ylabel("Probability density function");
title("Normal distributions for various parameter values");
disp("Kunal Dua")
disp("35614802722")
