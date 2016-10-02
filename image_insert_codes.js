(function ($) {

  Drupal.behaviors.imageinsertcodes = {
    attach: function (context, settings) {
      $('.imageinsertcodes', context).focus(function(){
        this.select();
      });
    }
  };

})(jQuery);
