(function ($) {

  Drupal.behaviors.imageinsertcodes = {
    attach: function (context, settings) {
      $('.imageinsertcodes').focus(function(){
        this.select();
      });
    }
  };

})(jQuery);
