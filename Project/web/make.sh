#!/bin/bash
export GEM_HOME="$HOME/gems"
export PATH="$HOME/gems/bin:$PATH"
bundle exec jekyll build
rm -r ../web/
cp -R _site/ ../web/
