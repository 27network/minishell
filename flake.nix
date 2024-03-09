{
  description = "A development environment for minishell";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = {
    self,
    nixpkgs,
  }: let
    system = "x86_64-linux";
    pkgs = nixpkgs.legacyPackages.${system};
    stdenv = pkgs.stdenvAdapters.useMoldLinker pkgs.clang17Stdenv;
  in {
    devShells.${system}.default = (pkgs.mkShell.override {inherit stdenv;}) {
      name = "minishell";
      packages = with pkgs; [
        readline
        valgrind
      ];
    };
  };
}
# vim: ts=2 sw=2 et

