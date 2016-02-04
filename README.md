# Byte Beat for OS X

A collection of simple programs that generate 8-bit sound & images.

# !!!WATCH YOUR EARS!!!

Audio produce by this application can damage _hearing_, and equipment.
Always run signals produced here into an compressor/envelope/amp/attenuator/attenuverter

    [ mac ]--+
             |
             $~ Compressor
             |
             +-->[ headphone amp ]--+
                                    |
                                    $~ Reduce
                                    |
                                    +-->[ you ]

## Installation

Just ensure your on OS X 10.11, and have Xcode installed

    git clone https://github.com/emcconville/bytebeatx.git
    cd bytebeatx
    xcodebuild
    sudo cp build/Release/bytebeat /usr/local/bin/bytebeat

