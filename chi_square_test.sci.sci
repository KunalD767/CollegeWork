function chi_square_exp_test(data)
    lambda = 1 / mean(data);
    n = length(data);

    bins = [0, 1, 2, 3, 4, 5]; // Adjust as needed
    bin_count = length(bins) - 1;

    hist_output = histc(data, bins);
    observed = hist_output(1:bin_count); // exclude overflow

    expected = [];
    for i = 1:bin_count
        p = exp(-lambda * bins(i)) - exp(-lambda * bins(i+1));
        expected($+1) = p * n;
    end

    // Filter bins with expected >= 5
    valid = find(expected >= 5);
    observed = observed(valid);
    expected = expected(valid);

    // 🛑 Check for enough bins
    if length(observed) < 2 then
        disp("❗ Not enough valid bins (with expected ≥ 5) to run Chi-square test.");
        return;
    end

    // Chi-square statistic and df
    chi_stat = sum(((observed - expected).^2) ./ expected);
    df = length(observed) - 1;

    // Use hardcoded critical values for alpha = 0.05
    select df
        case 1 then critical = 3.841;
        case 2 then critical = 5.991;
        case 3 then critical = 7.815;
        case 4 then critical = 9.488;
        case 5 then critical = 11.070;
        else
            mprintf("❗ df = %d not supported for critical value lookup.\n", df);
            return;
    end

    // Results
    mprintf("Chi-square statistic: %.4f\n", chi_stat);
    mprintf("Degrees of freedom: %d\n", df);
    mprintf("Critical value at alpha = 0.05: %.4f\n", critical);

    if chi_stat < critical then
        disp("✅ Fail to reject H₀: Data likely follows exponential distribution.");
    else
        disp("❌ Reject H₀: Data does not follow exponential distribution.");
    end
endfunction

// Example run
data = [1.2, 2.4, 0.9, 1.7, 3.2, 2.8, 1.5, 1.9, 3.1, 2.3];
chi_square_exp_test(data);
