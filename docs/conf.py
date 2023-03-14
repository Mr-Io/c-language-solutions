# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

project = 'Solutions 2nd Edition'
copyright = '2023, mr-io'
author = 'mr-io'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = []

templates_path = ['_templates']
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']



# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = 'alabaster'
html_static_path = ['_static']
html_theme_options = {
    # logo options
    'logo': 'logo.png',
    'logo_name': 'true',
    'description': 'answer C book',
    # github options
    'github_user': 'mr-io',
    'github_repo': 'the-c-programming-language-2nd-edition',
    'github_banner': 'true',
    'github_button': 'true',
    # sidebar options
    'fixed_sidebar': 'true',
    # footer options
    'show_powered_by': 'false',
    # style colors
    'pre_bg': '#FFFFCC',
    'code_highlight': '#FFFF80',
}
