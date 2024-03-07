/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   features.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:58:04 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/07 06:45:04 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FEATURES_H
# define FEATURES_H

// lol overrides
// TODO: remove this
# define BONUS_MSH 1
# define EXTRA_MSH 1
# define BONUS_42SH 1

// Defaults

/// Minishell bonuses
# define FEAT_PARSER_WILDCARD 0
# define FEAT_TKN_OR 0
# define FEAT_TKN_AND 0
# define FEAT_TKN_PAR 0

/// Minishell extras
# define FEAT_PROMPT_PICKER 0

/// 42sh features
# define FEAT_TKN_INLINE_ENV_DEF 0
# define FEAT_TKN_ESCAPE 0
# define FEAT_PARSER_WILDCARD_EXT 0
# define FEAT_BUILTIN_HELP 0
# define FEAT_BUILTIN_HELP_SET 0

// Definitions

/// 42sh features
# ifdef BONUS_42SH
#  undef FEAT_PARSER_WILDCARD_EXT
#  undef FEAT_TKN_INLINE_ENV_DEF
#  undef FEAT_TKN_ESCAPE
#  undef FEAT_BUILTIN_HELP
#  undef FEAT_BUILTIN_HELP_SET

#  define FEAT_PARSER_WILDCARD_EXT 1
#  define FEAT_TKN_INLINE_ENV_DEF 1
#  define FEAT_TKN_ESCAPE 1
#  define FEAT_BUILTIN_HELP 1
#  define FEAT_BUILTIN_HELP_SET 1

#  ifndef BONUS_MSH
#   define BONUS_MSH
#  endif
# endif

/// Minishell extras
# ifdef EXTRA_MSH
#  undef FEAT_PROMPT_PICKER

#  define FEAT_PROMPT_PICKER 1
# endif

/// Minishell bonuses
# ifdef BONUS_MSH
#  undef FEAT_PARSER_WILDCARD
#  undef FEAT_TKN_OR
#  undef FEAT_TKN_AND
#  undef FEAT_TKN_PAR

#  define FEAT_PARSER_WILDCARD 1
#  define FEAT_TKN_OR 1
#  define FEAT_TKN_AND 1
#  define FEAT_TKN_PAR 1
# endif

#endif // FEATURES_H
