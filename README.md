This is repository contains the source and simulation files for a binary perceptron that was made in Python, C++ (HLS) and VHDL.

This project was made in Collaboration with my ENGG3050 Team Andrew, Mina and Rafay.

If you're interested in using the C++ files for HLS, you might need to use Vivado SDK.

For VHDL, we were using the Arctix A7.

If you run the profiles for all 3 methods, you'll that VHDL was the fastest implementation. C++ was slower than VHDL due to the fact that HLS' 
packing, placement, and routing is not as efficient, but is easier to code.
