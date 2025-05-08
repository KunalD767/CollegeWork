function chi_square_exp_test(data)
    lambda = 1 / mean(data);
    n = length(data);

    bins = [0, 1, 2, 3, 4, 5];
    bin_count = length(bins) - 1;

    hist_output = histc(data, bins);
    observed = hist_output(1:bin_count);

    expected = [];
    for i = 1:bin_count
        p = exp(-lambda * bins(i)) - exp(-lambda * bins(i+1));
        expected($+1) = p * n;
    end

    valid = find(expected >= 5);
    observed = observed(valid);
    expected = expected(valid);

    if length(observed) < 2 then
        disp("❗ Not enough valid bins (expected ≥ 5).");
        return;
    end

    chi_stat = sum(((observed - expected).^2) ./ expected);
    df = length(observed) - 1;

    select df
        case 1 then critical = 3.841;
        case 2 then critical = 5.991;
        case 3 then critical = 7.815;
        case 4 then critical = 9.488;
        case 5 then critical = 11.070;
        else
            mprintf("❗ df = %d not supported.\n", df);
            return;
    end

    mprintf("Chi-square: %.4f\n", chi_stat);
    mprintf("Degrees of freedom: %d\n", df);
    mprintf("Critical value: %.4f\n", critical);

    if chi_stat < critical then
        disp("✅ Pass: Data likely exponential.");
    else
        disp("❌ Fail: Data not exponential.");
    end
endfunction

// ----------- Test run code -------------
disp("🧪 Running Chi-square Test on Sample Data...");
data = [1.2, 2.4, 0.9, 1.7, 3.2, 2.8, 1.5, 1.9, 3.1, 2.3];
chi_square_exp_test(data);
