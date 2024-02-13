/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   features.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:58:04 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/12 09:52:44 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FEATURES_H
# define FEATURES_H

# ifndef FEAT_PARSER
#  define FEAT_PARSER 1
# endif

# define FEAT_PARSER_PIPE 1
# define FEAT_PARSER_REDIR 1
# define FEAT_PARSER_HEREDOC 1
# define FEAT_PARSER_SEMICOLON 1
# define FEAT_PARSER_AND 1
# define FEAT_PARSER_OR 1
# define FEAT_PARSER_QUOTE 1

# define FEAT_EXEC 1

# define FEAT_BUILTIN 1

# define FEAT_CLI 1
# define FEAT_CLI_DASH_C 1
# define FEAT_CLI_SCRIPT_RUNNER 0

#endif // FEATURES_H
