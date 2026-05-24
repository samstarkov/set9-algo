clear;
clc;

pkg load symbolic;

function showTimePlot(dataFile, titleStr)
  data = load(dataFile);
  x = data(:, 1);

  figure;
  hold on;

  plot(x, data(:, 2), 'LineWidth', 1.2);
  plot(x, data(:, 3), 'LineWidth', 1.2);
  plot(x, data(:, 4), 'LineWidth', 1.2);
  plot(x, data(:, 5), 'LineWidth', 1.2);
  plot(x, data(:, 6), 'LineWidth', 1.2);
  plot(x, data(:, 7), 'LineWidth', 1.2);

  xlabel('Array size (n)');
  ylabel('Time (microseconds)');
  title(titleStr, 'FontSize', 14);
  legend('MergeSort', 'QuickSort', 'MergeSortLCP', 'TernaryQuickSort', 'MSDRadixSort', 'HybridRadixSort', 'Location', 'northwest');
  grid on;
  hold off;
endfunction

function showCmpPlot(dataFile, titleStr)
  data = load(dataFile);
  x = data(:, 1);

  figure;
  hold on;

  plot(x, data(:, 2), 'LineWidth', 1.2);
  plot(x, data(:, 3), 'LineWidth', 1.2);
  plot(x, data(:, 4), 'LineWidth', 1.2);
  plot(x, data(:, 5), 'LineWidth', 1.2);
  plot(x, data(:, 6), 'LineWidth', 1.2);
  plot(x, data(:, 7), 'LineWidth', 1.2);

  xlabel('Array size (n)');
  ylabel('Character comparisons');
  title(titleStr, 'FontSize', 14);
  legend('MergeSort', 'QuickSort', 'MergeSortLCP', 'TernaryQuickSort', 'MSDRadixSort', 'HybridRadixSort', 'Location', 'northwest');
  grid on;
  hold off;
endfunction

showTimePlot('TimeRandom.txt', 'Time - Random array');
showTimePlot('TimeReversed.txt', 'Time - Reversed array');
showTimePlot('TimeAlmostSorted.txt', 'Time - Almost sorted array');

showCmpPlot('ComparisonsRandom.txt', 'Comparisons - Random array');
showCmpPlot('ComparisonsReversed.txt', 'Comparisons - Reversed array');
showCmpPlot('ComparisonsAlmostSorted.txt', 'Comparisons - Almost sorted array');
